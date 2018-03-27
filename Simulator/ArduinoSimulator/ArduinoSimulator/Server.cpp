#include "Server.h"

#include <winsock.h>

Server::Server()
{

}

void Server::begin(unsigned int port)
{
	m_BackgroundListenerThread = std::thread(&Server::BackgroundListener, this);
}

void Server::stop()
{

}

void Server::BackgroundListener()
{

}
