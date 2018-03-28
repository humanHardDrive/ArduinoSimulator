#pragma once

#include <thread>
#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <stdio.h> 

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class Server
{
	public:
		Server();

		bool begin(PCSTR port);
		void stop();

	private:
		std::thread m_BackgroundListenerThread;
		SOCKET m_Listener;

	private:
		void BackgroundListener();
};