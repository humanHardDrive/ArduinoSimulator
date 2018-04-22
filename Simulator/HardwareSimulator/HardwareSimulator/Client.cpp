#include "Client.h"

#include <cstdio>

Client::Client()
{
	this->m_Socket = INVALID_SOCKET;
	this->m_Shutdown = false;
}

Client::Client(SOCKET sock)
{
	this->m_Socket = sock;
	this->m_Shutdown = false;

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

	closesocket(this->m_Socket);
}

void Client::setSocket(SOCKET sock)
{
	this->m_Socket = sock;

	if (this->m_BackgroundRecvThread.joinable() || this->m_BackgroundSendThread.joinable())
		disconnect();

	this->m_BackgroundRecvThread = std::thread(&Client::BackgroundRecv, this);
	this->m_BackgroundSendThread = std::thread(&Client::BackgroundSend, this);
}

SOCKET Client::socket()
{
	return this->m_Socket;
}

int Client::BackgroundRecv()
{
	char buffer[1024];
	int bytesRead = 0;

	while (!this->m_Shutdown)
	{
		bytesRead = recv(this->m_Socket, buffer, 1024, 0);

		if (bytesRead > 0)
			printf("Read %s\n", buffer);
		else if (WSAGetLastError() != WSAEWOULDBLOCK)
			this->disconnect();
	}

	return 0;
}

void Client::BackgroundSend()
{
	while (!this->m_Shutdown)
	{

	}
}
