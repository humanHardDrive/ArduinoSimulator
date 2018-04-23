#include "Client.h"

#include <cstdio>

Client::Client()
{
	this->m_Socket = INVALID_SOCKET;
	this->m_Shutdown = false;
	this->m_Disconnected = false;

	this->m_MsgHandler = NULL;
}

Client::Client(SOCKET sock)
{
	this->m_Socket = sock;
	this->m_Shutdown = false;
	this->m_Disconnected = false;

	this->m_MsgHandler = NULL;

	this->m_BackgroundRecvThread = std::thread(&Client::BackgroundRecv, this);
	this->m_BackgroundSendThread = std::thread(&Client::BackgroundSend, this);
}

Client::~Client()
{
}

void Client::disconnect()
{
	this->m_Shutdown = true;
	shutdown(this->m_Socket, SD_BOTH);

	if (this->m_BackgroundRecvThread.joinable())
		this->m_BackgroundRecvThread.join();

	if (this->m_BackgroundSendThread.joinable())
		this->m_BackgroundSendThread.join();

	closesocket(this->m_Socket);
	this->m_Socket = INVALID_SOCKET;
}

void Client::setSocket(SOCKET sock)
{
	this->m_Socket = sock;
	this->m_Shutdown = false;
	this->m_Disconnected = false;

	if (this->m_BackgroundRecvThread.joinable() || this->m_BackgroundSendThread.joinable())
		disconnect();

	this->m_BackgroundRecvThread = std::thread(&Client::BackgroundRecv, this);
	this->m_BackgroundSendThread = std::thread(&Client::BackgroundSend, this);
}

void Client::SetMsgHandler(void(*MsgHandler)(char* msg, size_t size, Client* c))
{
	this->m_MsgHandler = MsgHandler;
}

SOCKET Client::socket()
{
	return this->m_Socket;
}

void Client::write(std::string msg)
{
	this->m_QLock.lock();
	this->m_MsgQ.push(msg);
	this->m_QLock.unlock();
}

bool Client::isDisconnected()
{
	return m_Disconnected;
}

int Client::BackgroundRecv()
{
	char buffer[1024];
	int bytesRead = 0;

	while (!this->m_Shutdown)
	{
		bytesRead = recv(this->m_Socket, buffer, 1024, 0);

		if (bytesRead > 0)
		{
			if (this->m_MsgHandler)
				this->m_MsgHandler(buffer, bytesRead, this);
		}
		else if (WSAGetLastError() != WSAEWOULDBLOCK)
			this->m_Disconnected = true;
	}

	return 0;
}

int Client::BackgroundSend()
{
	while (!this->m_Shutdown)
	{
		this->m_QLock.lock();

		if (this->m_MsgQ.size() > 0)
		{
			std::string msg = this->m_MsgQ.front();
			this->m_MsgQ.pop();

			send(this->m_Socket, msg.c_str(), msg.size(), 0);
		}

		this->m_QLock.unlock();
	}

	return 0;
}
