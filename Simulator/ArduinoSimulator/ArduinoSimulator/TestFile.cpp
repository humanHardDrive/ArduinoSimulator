#include "Simulator.h"

void setup()
{
	DDRB = 0xFF;
}

void loop()
{
	PORTB ^= 0xAA;
}