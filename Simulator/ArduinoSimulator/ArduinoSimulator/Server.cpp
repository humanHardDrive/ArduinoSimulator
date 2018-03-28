#include "Server.h"
#include "Logging.h"

#include <errno.h>

Server::Server()
{
}

bool Server::begin(PCSTR port)
{
	// create WSADATA object
	WSADATA wsaData;
	int iResult;

	// our sockets for the server
	m_Listener = INVALID_SOCKET;

	// address info for the server to listen to
	struct addrinfo *result = NULL;
	struct addrinfo hints;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) 
	{
		printf("WSAStartup failed with error: %d\n", iResult);
		exit(1);
	}

	// set address information
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;    // TCP connection!!!
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, port, &hints, &result);

	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		exit(1);
	}

	// Create a SOCKET for connecting to server
	m_Listener = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	if (m_Listener == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		exit(1);
	}

	// Set the mode of the socket to be nonblocking
	u_long iMode = 1;
	iResult = ioctlsocket(m_Listener, FIONBIO, &iMode);

	if (iResult == SOCKET_ERROR) 
	{
		printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
		closesocket(m_Listener);
		WSACleanup();
		exit(1);
	}

	// Setup the TCP listening socket
	iResult = bind(m_Listener, result->ai_addr, (int)result->ai_addrlen);

	if (iResult == SOCKET_ERROR)
	{
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(m_Listener);
		WSACleanup();
		exit(1);
	}

	// no longer need address information
	freeaddrinfo(result);

	// start listening for new clients attempting to connect
	iResult = listen(m_Listener, SOMAXCONN);

	if (iResult == SOCKET_ERROR) 
	{
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(m_Listener);
		WSACleanup();
		exit(1);
	}

	m_BackgroundListenerThread = std::thread(&Server::BackgroundListener, this);

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
