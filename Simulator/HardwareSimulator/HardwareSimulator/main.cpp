#include <iostream>
#include <thread>
#include <chrono>

#include "Connection.h"
#include "Server.h"

int main(int argc, char** argv)
{
	//Connection c("127.0.0.1", "8080");
	Server s("127.0.0.1", "8080", 10);

	/*if (c.start())
	{
		for (int i = 0; i < 10; i++)
		{
			using namespace std::chrono_literals;
			c.write("{\"pin\":\"10\", \"type\":\"serial\", \"baud\":\"9600\", \"data\":\"AB\"}");
			std::this_thread::sleep_for(2s);
		}
		c.stop();
	}*/

	s.start();
	while (1);

	return 0;
}