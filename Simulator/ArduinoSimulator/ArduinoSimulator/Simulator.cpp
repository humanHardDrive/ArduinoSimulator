#include "Simulator.h"

void SetupRegisterFile()
{
	Register8 DDRB(0x00);
	Register8 DDRC(0x00);
	Register8 DDRD(0x00);

	Register8 PORTB(0x00);
	Register8 PORTC(0x00);
	Register8 PORTD(0x00);

	Register8 PINB(0x00);
	Register8 PINC(0x00);
	Register8 PIND(0x00);
}
