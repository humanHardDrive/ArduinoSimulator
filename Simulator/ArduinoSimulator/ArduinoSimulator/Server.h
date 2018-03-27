#pragma once

#include <Windows.h>
#include <thread>

class Server
{
	public:
		Server();

		void begin(unsigned int port);
		void stop();

	private:
		std::thread m_BackgroundListenerThread;

	public:
		void BackgroundListener();
};