#include <iostream>
#include <cstdint>

using namespace std;

#define VAR_BYTE(var, byte)		((uint8_t*)(&var)[byte])
#define BIT_SET(var, bit)		(var & (1 << bit))

void l_NOP()
{
	std::cout << "NOP" << std::endl;
}

//https://en.wikipedia.org/wiki/Atmel_AVR_instruction_set
void ParseInstruction(uint16_t inst)
{
	uint8_t instcode = VAR_BYTE(inst, 3);
	uint8_t opcode = instcode;

	//Easy case
	if(!inst)
	{
		l_NOP();
		return;
	}

	//Get the 2 most significant bits
	instcode = (instcode & 0xC0) >> 6;

	switch(instcode)
	{
		case 0:
			if(opcode & 0xFC)
			{
				//2 operand instructions
				opcode = (opcode & 0x3C) >> 2;
			}
			else
			{
				//These instructions are weird and don't seem to belong
				//to any set. Handle these later
			}
			break;

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;
	}
}

int main()
{
}
