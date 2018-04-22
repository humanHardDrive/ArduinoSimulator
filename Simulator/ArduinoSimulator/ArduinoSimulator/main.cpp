#include <iostream>
#include <cstdlib>

//#include "Simulator.h"
//#include "Logging.h"

#include "Connection.h"

#define VERSION_MINOR	0
#define VERSION_MAJOR	0


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

	//setup();
	while (connected && !stopRunning)
	{
		if (connected)
			c.write("HELLO WORLD");

		//loop();
		stopRunning = true;
	}

	c.stop();

	return 1;
}