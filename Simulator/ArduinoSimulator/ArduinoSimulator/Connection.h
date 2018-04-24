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

class Connection
{
public:
	Connection(std::string ip, std::string port);
	Connection();
	~Connection();

	bool start();
	void stop();
	void write(std::string msg);

	void SetMsgHandler(void(*MsgHandler)(char* msg, size_t size, Connection* c));

	bool isDisconnected();

private:
	void ConnectionSendBackground();
	void ConnectionRecvBackground();

private:
	SOCKET ConnectionSocket;
	std::thread m_BackgroundRecvThread;
	std::thread m_BackgroundSendThread;

	void(*m_MsgHandler)(char* msg, size_t size, Connection* c);

	bool m_StopConnection;
	bool m_Disconnected;

	std::string m_IP, m_Port;
	std::queue<std::string> m_MsgQ;
	std::mutex m_QLock;
};

