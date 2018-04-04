#pragma once

#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <stdio.h> 

#include <thread>
#include <mutex>

#include <string>
#include <queue>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class Server
{
public:
	Server(std::string ip, std::string port);
	~Server();

	bool start();
	void stop();

private:
	SOCKET m_Socket;

	bool m_StopServer;

	std::string m_IP, m_Port;

	std::thread m_BackgroundAcceptThread;
	std::thread m_BackgroundSendThread;
	std::thread m_BackgroundRecvThread;
};

