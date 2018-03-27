#pragma once

class Server
{
	public:
		Server();

		void begin(unsigned int port);
		void stop();
};