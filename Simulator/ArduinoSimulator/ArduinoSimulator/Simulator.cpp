#include "Simulator.h"

PIN_MODE l_CurrentPinMode[PIN_COUNT];
PIN_STATE l_CurrentPinState[PIN_COUNT];

unsigned int l_SystemMilliSecClk = 0;

void pinMode(uint8_t pin, PIN_MODE mode)
{

}


PIN_STATE digitalRead(uint8_t pin)
{
	return l_CurrentPinState[pin];
}

void digitalWrite(uint8_t pin, PIN_STATE state)
{

}


DWORD WINAPI IncrementSystemMilliSecsClk(LPVOID lpParam)
{
	l_SystemMilliSecClk++;
	return 0;
}

unsigned int millis()
{
	return l_SystemMilliSecClk;
}

void delay(unsigned int ms)
{
	unsigned int CurrentTime = millis();

	while ((CurrentTime + ms) > millis());
}