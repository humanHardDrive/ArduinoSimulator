#include "Simulator.h"

#include <cstdio>

Register8 DDRB("DDRB", 0x00, false);
Register8 DDRC("DDRC", 0x00, false);
Register8 DDRD("DDRD", 0x00, false);

Register8 PORTB("PORTB", 0x00, false);
Register8 PORTC("PORTC", 0x00, false);
Register8 PORTD("PORTD", 0x00, false);

Register8 PINB("PINB", 0x00, true);
Register8 PINC("PINC", 0x00, true);
Register8 PIND("PIND", 0x00, true);

Connection c("127.0.0.1", "4040");

void BasicChangeNotification(Register8* reg)
{
	char buffer[128];
	sprintf_s(buffer, "{\"register\":\"%s\",\"value\":\"0x%x\"}", reg->name.c_str(), reg->value);

	std::string msg(buffer);
	c.write(msg);
}

void SetupHardwareSimConnection(std::string ip, std::string port)
{
	c.start();
}

void SetupRegisterChangeEvents()
{
	DDRB.SetOnChange(BasicChangeNotification);
	DDRC.SetOnChange(BasicChangeNotification);
	DDRD.SetOnChange(BasicChangeNotification);

	PORTB.SetOnChange(BasicChangeNotification);
	PORTC.SetOnChange(BasicChangeNotification);
	PORTD.SetOnChange(BasicChangeNotification);
}