#include "Client.h"

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

	m_BackgroundRecvThread.join();
	m_BackgroundSendThread.join();

	closesocket(this->m_Socket);
}

void Client::BackgroundRecv()
{
	char buffer[1024];
}

void Client::BackgroundSend()
{

}
