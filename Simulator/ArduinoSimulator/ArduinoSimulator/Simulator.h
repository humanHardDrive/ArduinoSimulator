#pragma once
#include <cstdint>

#include <Windows.h>

#include "Serial.h"

#define PIN_COUNT	20

typedef byte uint8_t;

typedef enum
{
	INPUT1 = 0, //Input is defined by something else?
	OUTPUT,
	INPUT_PULLUP
}PIN_MODE;

enum PIN_STATE
{
	LOW = 0,
	HIGH
};

void setup();
void loop();

void pinMode(uint8_t pin, PIN_MODE mode);

PIN_STATE digitalRead(uint8_t pin);
void digitalWrite(uint8_t pin, PIN_STATE state);

DWORD WINAPI IncrementSystemMilliSecsClk(LPVOID lpParam);
unsigned int millis();
void delay(unsigned int ms);