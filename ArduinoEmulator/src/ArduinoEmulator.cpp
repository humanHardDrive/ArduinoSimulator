#include <iostream>
#include <cstdint>

using namespace std;

void l_NOP()
{
	std::cout << "NOP" << std::endl;
}

//2-operand instructions
void l_CP(uint8_t rd, uint8_t rr)
{
	std::cout << "CP" << std::endl;
}

void l_CPC(uint8_t rd, uint8_t rr)
{
	std::cout << "CPC" << std::endl;
}

void l_SUB(uint8_t rd, uint8_t rr)
{
	std::cout << "SUB" << std::endl;
}

void l_SBC(uint8_t rd, uint8_t rr)
{
	std::cout << "SBC" << std::endl;
}

void l_ADD(uint8_t rd, uint8_t rr)
{
	std::cout << "ADD" << std::endl;
}

void l_ADC(uint8_t rd, uint8_t rr)
{
	std::cout << "ADC" << std::endl;
}

void l_CPSE(uint8_t rd, uint8_t rr)
{
	std::cout << "CPSE" << std::endl;
}

void l_AND(uint8_t rd, uint8_t rr)
{
	std::cout << "AND" << std::endl;
}

void l_EOR(uint8_t rd, uint8_t rr)
{
	std::cout << "EOR" << std::endl;
}

void l_OR(uint8_t rd, uint8_t rr)
{
	std::cout << "OR" << std::endl;
}

void l_MOV(uint8_t rd, uint8_t rr)
{
	std::cout << "MOV" << std::endl;
}

void l_CPI(uint8_t rd, uint8_t k)
{
	std::cout << "CPI" << std::endl;
}

/*
 *The opcodes for this method were found here:
 *https://en.wikipedia.org/wiki/Atmel_AVR_instruction_set
 *The opcodes also exist in the AVR specification, but the Wiki
 *provides a nice table that made writing the parser much easier
 *than organizing all of the entries from AVR's documentation.
*/
bool ParseInstruction(uint16_t inst)
{
	uint8_t instcode = ((uint8_t*)(&inst))[3];
	uint8_t opcode = instcode;

	//Easy case
	if(!inst)
	{
		l_NOP();
		return true;
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
				switch(opcode)
				{
					case 1:
						l_CPC(0, 0);
						return true;
						break;

					case 2:
						l_SBC(0, 0);
						return true;
						break;

					//The Wiki entry for this opcode is wrong, at time of writing 7/22/18
					//From the AVR documentation no part of the register is in the opcode
					//According to the Wiki, there would be a collision between this instruction
					//and the SBC instruction
					case 3:
						l_ADD(0, 0);
						return true;
						break;

					case 4:
						l_CPSE(0, 0);
						return true;
						break;

					case 5:
						l_CP(0, 0);
						return true;
						break;

					case 6:
						l_SUB(0,0);
						return true;
						break;

					case 7:
						l_ADC(0,0);
						return true;
						break;

					case 8:
						l_AND(0, 0);
						return true;
						break;

					case 9:
						l_EOR(0, 0);
						return true;
						break;

					case 10:
						l_OR(0, 0);
						return true;
						break;

					case 11:
						l_MOV(0,0);
						return true;
						break;

					//This isn't a 2-operand instruction, but the instruction code is 0
					//So I'll handle it here, even though part of the constant is in the opcode
					case 12:
					case 13:
					case 14:
					case 15:
						l_CPI(0, 0);
						return true;
						break;

					default:
						std::cout << "UNKOWN " << inst << std::endl;
						return false;
						break;
				}
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

	return false;
}

int main()
{
}
