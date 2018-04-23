#include "Connection.h"

Connection::Connection(std::string ip, std::string port)
{
	this->m_IP = ip;
	this->m_Port = port;

	this->m_MsgHandler = NULL;

	this->m_StopConnection = false;
}

Connection::~Connection()
{
}

bool Connection::start()
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
		return false;
	}

	// set address info
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;  //TCP connection!!!

									  //resolve server address and port
	iResult = getaddrinfo(this->m_IP.c_str(), this->m_Port.c_str(), &hints, &result);

	if (iResult != 0)
	{
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return false;
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

		// Create a SOCKET for connecting to server
		this->ConnectionSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);

		if (this->ConnectionSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return false;
		}

		// Connect to server.
		iResult = connect(this->ConnectionSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

		if (iResult == SOCKET_ERROR)
		{
			closesocket(this->ConnectionSocket);
			this->ConnectionSocket = INVALID_SOCKET;
			printf("The server is down... did not connect");
			return false;
		}
	}

	// no longer need address info for server
	freeaddrinfo(result);

	// if connection failed
	if (this->ConnectionSocket == INVALID_SOCKET)
	{
		printf("Unable to connect to server!\n");
		WSACleanup();
		return false;
	}

	iResult = ioctlsocket(this->ConnectionSocket, FIONBIO, &iMode);
	if (iResult == SOCKET_ERROR)
	{
		printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
		closesocket(this->ConnectionSocket);
		WSACleanup();
		return false;
	}

	m_BackgroundSendThread = std::thread(&Connection::ConnectionSendBackground, this);
	m_BackgroundRecvThread = std::thread(&Connection::ConnectionRecvBackground, this);

	return true;
}

void Connection::stop()
{
	this->m_StopConnection = true;
	shutdown(this->ConnectionSocket, SD_BOTH);
}

void Connection::write(std::string msg)
{
	this->m_QLock.lock();
	this->m_MsgQ.push(msg);
	this->m_QLock.unlock();
}

void Connection::SetMsgHandler(void(*MsgHandler)(char* msg, size_t size, Connection* c))
{
	this->m_MsgHandler = MsgHandler;
}

void Connection::ConnectionSendBackground()
{
	while (!this->m_StopConnection)
	{
		this->m_QLock.lock();

		if (this->m_MsgQ.size() > 0)
		{
			std::string msg = this->m_MsgQ.front();
			this->m_MsgQ.pop();

			send(this->ConnectionSocket, msg.c_str(), msg.size(), 0);
		}

		this->m_QLock.unlock();

		std::this_thread::yield();
	}
}

void Connection::ConnectionRecvBackground()
{
	char buffer[1024];
	int bytesRead = 0;
	
	while (!this->m_StopConnection)
	{
		bytesRead = recv(this->ConnectionSocket, buffer, 1024, 0);

		if (bytesRead > 0)
		{
			if (this->m_MsgHandler)
				this->m_MsgHandler(buffer, bytesRead, this);
		}
		else if (WSAGetLastError() != WSAEWOULDBLOCK)
			this->stop();

		std::this_thread::yield();
	}
}
