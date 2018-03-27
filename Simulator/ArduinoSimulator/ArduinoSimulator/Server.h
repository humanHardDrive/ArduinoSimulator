#pragma once

#include <thread>
#include <winsock.h>

#pragma comment(lib, "Ws2_32.lib")

class Server
{
	public:
		Server();

		bool begin(unsigned int port);
		void stop();

	private:
		std::thread m_BackgroundListenerThread;
		SOCKET m_Listener;

	private:
		void BackgroundListener();
};