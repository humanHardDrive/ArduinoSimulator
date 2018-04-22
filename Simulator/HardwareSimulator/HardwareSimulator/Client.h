#pragma once

#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <stdio.h> 
#include "Client.h"

#include <thread>

#include <string>
#include <queue>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class Client
{
public:
	Client();
	Client(SOCKET sock);
	~Client();

	void disconnect();

	void setSocket(SOCKET sock);
	SOCKET socket();

private:
	int BackgroundRecv();
	void BackgroundSend();

private:
	SOCKET m_Socket;

	bool m_Shutdown;

	std::thread m_BackgroundRecvThread;
	std::thread m_BackgroundSendThread;
};

