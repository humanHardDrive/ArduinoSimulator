#pragma once
#include "Arduino.h"

#include "Register16.h"
#include "Register8.h"

#include "Connection.h"

extern Register8 DDRB;
extern Register8 DDRC;
extern Register8 DDRD;

extern Register8 PORTB;
extern Register8 PORTC;
extern Register8 PORTD;

extern Register8 PINB;
extern Register8 PINC;
extern Register8 PIND;

//Basic Arduino methods
void setup();
void loop();

void SetupHardwareSimConnection(std::string ip, std::string port);

void SetupRegisterChangeEvents();