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
#include <vector>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class Server
{
public:
	Server(std::string ip, std::string port, unsigned int MaxConnections);
	~Server();

	bool start();
	void stop();

private:
	void ListenerBackground();

private:
	SOCKET m_Socket;

	bool m_StopServer;
	unsigned int m_MaxConnections;
	unsigned int m_CurrentConnections;

	std::vector<Client> m_Client;

	std::string m_IP, m_Port;

	std::thread m_BackgroundAcceptThread;
};

