#include <iostream>
#include <cstdlib>

#include "Simulator.h"

#define VERSION_MINOR	0
#define VERSION_MAJOR	0

int main(int argc, char** argv)
{
	std::cout << "Arduino Simulator v" << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

	SetupRegisterChangeEvents();
	SetupHardwareSimConnection("127.0.0.1", "4040");

	setup();
	while (1)
	{
		loop();
	}

	return 1;
}