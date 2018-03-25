#pragma once
#include <cstdint>

enum PIN_MODE
{
	INPUT = 0,
	OUTPUT,
	INPUT_PULLUP
};

void setup();
void loop();

void pinMode(uint8_t pin, PIN_MODE mode);
void digitalRead(uint8_t pin);
