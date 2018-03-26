#include <iostream>
#include <cstdlib>

#include "Simulator.h"

int main(int argc, char** argv)
{
	HANDLE SystemMilliSecClkInterrupt;
	bool stopRunning = false;

	SystemMilliSecClkInterrupt = CreateThread(NULL, 0, IncrementSystemMilliSecsClk, NULL, 0, NULL);

	setup();
	while (!stopRunning)
	{
		loop();
	}

	return 1;
}