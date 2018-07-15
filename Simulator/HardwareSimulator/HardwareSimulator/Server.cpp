#include "Server.h"

Server::Server(std::string ip, std::string port, unsigned int MaxConnections)
{
	this->m_IP = ip;
	this->m_Port = port;

	this->m_MaxConnections = MaxConnections;
	this->m_CurrentConnections = 0;
}

Server::~Server()
{
}


bool Server::start()
{
	// create WSADATA object
	WSADATA wsaData;
	int iResult;

	// our sockets for the server
	this->m_Socket = INVALID_SOCKET;

	// address info for the server to listen to
	struct addrinfo *result = NULL;
	struct addrinfo hints;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);
		return false;
	}

	// set address information
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;    // TCP connection!!!
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, this->m_Port.c_str(), &hints, &result);

	if (iResult != 0) 
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();

		return false;
	}

	// Create a SOCKET for connecting to server
	this->m_Socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	if (!this->m_Socket)
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();

		return false;
	}

	// Set the mode of the socket to be nonblocking
	u_long iMode = 1;
	iResult = ioctlsocket(this->m_Socket, FIONBIO, &iMode);

	if (iResult < 0) {
		printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
		closesocket(this->m_Socket);
		WSACleanup();

		return false;
	}

	// Setup the TCP listening socket
	iResult = bind(this->m_Socket, result->ai_addr, (int)result->ai_addrlen);

	if (iResult < 0)
	{
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(this->m_Socket);
		WSACleanup();

		return false;
	}

	// no longer need address information
	freeaddrinfo(result);

	// start listening for new clients attempting to connect
	iResult = listen(this->m_Socket, SOMAXCONN);

	if (iResult < 0)
	{
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(this->m_Socket);
		WSACleanup();

		return false;
	}

	m_BackgroundAcceptThread = std::thread(&Server::ListenerBackground, this);

	return true;
}

void Server::stop()
{
	this->m_StopServer = true;
}

void Server::ListenerBackground()
{
	while (!m_StopServer)
	{
		if (this->m_CurrentConnections < this->m_MaxConnections)
		{
			struct sockaddr_in clientaddr;
			int addrlen;
			SOCKET client;

			client = accept(this->m_Socket, (struct sockaddr*)&clientaddr, &addrlen);
			if (client != INVALID_SOCKET)
			{
				this->m_CurrentConnections++;
				printf("New client. Current connections %d/%d\n", this->m_CurrentConnections, this->m_MaxConnections);

				this->m_Client.emplace_back(client);
			}
		}
	}
}
