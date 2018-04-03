#include "Connection.h"



Connection::Connection()
{
	// create WSADATA object
	WSADATA wsaData;
	this->ConnectionSocket = INVALID_SOCKET;
	int iResult;
	u_long iMode = 1;

	// holds address info for socket to connect to
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != 0)
	{
		printf("WSAStartup failed with error: %d\n", iResult);
		//exit(1);
	}

	// set address info
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;  //TCP connection!!!

									  //resolve server address and port
	iResult = getaddrinfo("127.0.0.1", "8080", &hints, &result);

	if (iResult != 0)
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		//exit(1);
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

		// Create a SOCKET for connecting to server
		this->ConnectionSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);

		if (this->ConnectionSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			//exit(1);
		}

		// Connect to server.
		iResult = connect(this->ConnectionSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

		if (iResult == SOCKET_ERROR)
		{
			closesocket(this->ConnectionSocket);
			this->ConnectionSocket = INVALID_SOCKET;
			printf("The server is down... did not connect");
		}
	}

	// no longer need address info for server
	freeaddrinfo(result);

	// if connection failed
	if (this->ConnectionSocket == INVALID_SOCKET)
	{
		printf("Unable to connect to server!\n");
		WSACleanup();
		//exit(1);
	}

	iResult = ioctlsocket(this->ConnectionSocket, FIONBIO, &iMode);
	if (iResult == SOCKET_ERROR)
	{
		printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
		closesocket(this->ConnectionSocket);
		WSACleanup();
		//exit(1);
	}
}


Connection::~Connection()
{
}
