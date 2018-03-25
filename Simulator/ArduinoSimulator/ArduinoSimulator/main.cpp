#include <iostream>
#include <cstdlib>

#include "Simulator.h"

int main(int argc, char** argv)
{
	bool stopRunning = false;

	setup();
	while (!stopRunning)
	{
		loop();
	}

	return 1;
}