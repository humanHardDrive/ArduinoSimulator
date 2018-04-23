#include <iostream>
#include <cstdlib>

#include "Simulator.h"

#include "Connection.h"

#define VERSION_MINOR	0
#define VERSION_MAJOR	0

void msghandler(char* msg, size_t size, Connection* c)
{
	std::string smsg(msg, size);

	printf("Connection says %s\n", smsg.c_str());
	c->write(smsg);
}

int main(int argc, char** argv)
{
	std::cout << "Arduino Simulator v" << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

	Connection c("127.0.0.1", "4040");
	c.SetMsgHandler(msghandler);

	SetupRegisterFile();

	setup();
	while (!c.isDisconnected());
	{
		if (c.isDisconnected())
			c.stop();
		loop();
	}

	c.stop();

	return 1;
}