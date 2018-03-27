#include "Server.h"

#include "Logging.h"

Server::Server()
{
}

bool Server::begin(unsigned int port)
{
	char opt = 1;
	struct sockaddr_in address;

	DISPLAY_LOG(LVL_INFO, "Starting server on port %d...", port);
	if ((m_Listener = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		DISPLAY_LOG(LVL_ERROR, "Failed to create socket");
		return false;
	}

	DISPLAY_LOG(LVL_INFO, "Setting socket options...");
	if (setsockopt(m_Listener, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		DISPLAY_LOG(LVL_ERROR, "Failed to set socket options");
		return false;
	}

	address.sin_family = AF_INET;
	address.sin_addr.S_un.S_addr = INADDR_ANY;
	address.sin_port = htons(port);

	DISPLAY_LOG(LVL_INFO, "Binding socket to port...");
	if (bind(m_Listener, (struct sockaddr*)&address, sizeof(address)) < 0)
	{
		DISPLAY_LOG(LVL_ERROR, "Failed to bind socket");
		return false;
	}

	DISPLAY_LOG(LVL_INFO, "Starting to listen...")
	if (listen(m_Listener, 16) < 0)
	{
		DISPLAY_LOG(LVL_ERROR, "Failed to listen");
		return false;
	}

	DISPLAY_LOG(LVL_INFO, "Starting listening thread...");
	//m_BackgroundListenerThread = std::thread(&Server::BackgroundListener, this);

	DISPLAY_LOG(LVL_INFO, "Success");
	return true;
}

void Server::stop()
{
	if (m_Listener)
		closesocket(m_Listener);
}

void Server::BackgroundListener()
{

}
