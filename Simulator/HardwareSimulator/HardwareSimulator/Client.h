#pragma once

#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <stdio.h> 
#include "Client.h"

#include <thread>
#include <mutex>

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
	Client(const Client &other);
	~Client();

	Client& operator=(const Client& other) = default;

	void disconnect();

	void setSocket(SOCKET sock);
	SOCKET socket();

	void SetMsgHandler(void(*MsgHandler)(char* msg, size_t size, Client* c));
	void write(std::string msg);

	bool isDisconnected();

private:
	int BackgroundRecv();
	int BackgroundSend();

private:
	SOCKET m_Socket;

	bool m_Shutdown;
	bool m_Disconnected;

	void(*m_MsgHandler)(char* msg, size_t size, Client* c);

	std::mutex m_QLock;
	std::queue<std::string> m_MsgQ;

	std::thread m_BackgroundRecvThread;
	std::thread m_BackgroundSendThread;
};

