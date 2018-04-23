#include <iostream>
#include <cstdlib>

//#include "Simulator.h"
//#include "Logging.h"

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
	HANDLE SystemMilliSecClkInterrupt;
	bool stopRunning = false;
	bool connected = false;

	std::cout << "Arduino Simulator v" << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
	//DISPLAY_LOG(LVL_INFO, "Logging Started. Execution Started");

	//SystemMilliSecClkInterrupt = CreateThread(NULL, 0, IncrementSystemMilliSecsClk, NULL, 0, NULL);

	Connection c("127.0.0.1", "4040");
	connected = c.start();
	c.SetMsgHandler(msghandler);

	if (connected)
		c.write("HELLO WORLD");

	//setup();
	while (!c.isDisconnected());
	{
		if (c.isDisconnected())
			c.stop();
		//loop();
	}

	c.stop();

	return 1;
}