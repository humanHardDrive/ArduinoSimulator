#include <iostream>
#include <cstdlib>

#include "Server.h"
#include "Simulator.h"
#include "Logging.h"

#define VERSION_MINOR	0
#define VERSION_MAJOR	0


int main(int argc, char** argv)
{
	HANDLE SystemMilliSecClkInterrupt;
	Server server;
	bool stopRunning = false;

	std::cout << "Arduino Simulator v" << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
	DISPLAY_LOG(LVL_INFO, "Logging Started. Execution Started");

	server.begin(8080);

	SystemMilliSecClkInterrupt = CreateThread(NULL, 0, IncrementSystemMilliSecsClk, NULL, 0, NULL);

	setup();
	while (!stopRunning)
	{
		loop();
		stopRunning = true;
	}

	server.stop();

	return 1;
}