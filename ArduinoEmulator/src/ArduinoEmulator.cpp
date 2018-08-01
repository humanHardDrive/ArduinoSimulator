#include <iostream>
#include <cstdint>
#include <cstring>
#include <map>
#include <functional>

typedef void (*InstructionHandler)(uint16_t);

std::map<uint16_t, InstructionHandler> InstructionMap;

void l_NOP(uint16_t inst)
{
	std::cout << "NOP" << std::endl;
}

void l_MOVW(uint16_t inst)
{
	std::cout << "MOVW" << std::endl;
}

void l_MULS(uint16_t inst)
{
	std::cout << "MULS" << std::endl;
}

void l_MULSU(uint16_t inst)
{
	std::cout << "MULSU" << std::endl;
}

void l_FMUL(uint16_t inst)
{
	std::cout << "FMUL" << std::endl;
}

void l_FMULS(uint16_t inst)
{
	std::cout << "FMULS" << std::endl;
}

void l_FMULSU(uint16_t inst)
{
	std::cout << "FMULSU" << std::endl;
}


//2-operand instructions
void l_CP(uint16_t inst)
{
	std::cout << "CP" << std::endl;
}

void l_CPC(uint16_t inst)
{
	std::cout << "CPC" << std::endl;
}

void l_SUB(uint16_t inst)
{
	std::cout << "SUB" << std::endl;
}

void l_SBC(uint16_t inst)
{
	std::cout << "SBC" << std::endl;
}

void l_ADD(uint16_t inst)
{
	std::cout << "ADD" << std::endl;
}

void l_ADC(uint16_t inst)
{
	std::cout << "ADC" << std::endl;
}

void l_CPSE(uint16_t inst)
{
	std::cout << "CPSE" << std::endl;
}

void l_AND(uint16_t inst)
{
	std::cout << "AND" << std::endl;
}

void l_EOR(uint16_t inst)
{
	std::cout << "EOR" << std::endl;
}

void l_OR(uint16_t inst)
{
	std::cout << "OR" << std::endl;
}

void l_MOV(uint16_t inst)
{
	std::cout << "MOV" << std::endl;
}

void l_CPI(uint16_t inst)
{
	std::cout << "CPI" << std::endl;
}


//Register-immediate operations
void l_SUBI(uint16_t inst)
{
	std::cout << "SUBI" << std::endl;
}

void l_SBCI(uint16_t inst)
{
	std::cout << "SUBC" << std::endl;
}

void l_ORI(uint16_t inst)
{
	std::cout << "ORI" << std::endl;
}

void l_ANDI(uint16_t inst)
{
	std::cout << "ANDI" << std::endl;
}

void l_LDD(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_STD(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}


//Load/store operations
void l_LDS(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_STS(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LDPostInc(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_STPostInc(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LDPreDec(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_STPreDec(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LPM(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_ELPM(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LPMPostInc(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_ELPMPostInc(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_XCH(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LAS(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LAC(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LAT(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LDX(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_STX(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LDXPostInc(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_STXPostInc(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LDXPreDec(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_STXPreDec(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_PUSH(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_POP(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}



//One-operand instructions
void l_COM(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_NEG(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SWAP(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_INC(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_ASR(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LSR(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_ROR(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SEB(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_CLB(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}


//Zero operand instructions
void l_RET(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_RETI(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SLEEP(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_BREAK(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_WDR(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LPM2(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_ELPM2(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SPM(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SPMPostInc(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}


void l_IJMP(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_ICALL(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_DEC(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_DES(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_JMP(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_CALL(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}


void l_ADIW(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SBIW(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_CBI(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SBI(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SBIC(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SBIS(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_MUL(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}


void l_IN(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_OUT(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_RJMP(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_RCALL(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_LDI(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_CBSR(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_BLD(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_BST(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SBRC(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}

void l_SBRS(uint16_t inst)
{
	std::cout << __FUNCTION__ << std::endl;
}


void AddInstructionToMap(char* inst, unsigned char index, unsigned short opcode, InstructionHandler handler)
{
	char copy0[20], copy1[20];

	if(!inst)
		return;

	strcpy(copy0, inst);
	strcpy(copy1, inst);

	while(inst[index])
	{
		if(inst[index] == 'x')
		{
			copy0[index] = '0';
			copy1[index] = '1';

			AddInstructionToMap(copy0, index, opcode, handler);
			AddInstructionToMap(copy1, index, opcode, handler);
			return;
		}
		else
		{
			opcode *= 2;
			opcode += inst[index] - '0';
		}

		index++;
	}

	InstructionMap.insert(std::pair<uint16_t, InstructionHandler>(opcode, handler));
}

/*
 *The opcodes for this method were found here:
 *https://en.wikipedia.org/wiki/Atmel_AVR_instruction_set
 *The opcodes also exist in the AVR specification, but the Wiki
 *provides a nice table that made writing the parser much easier
 *than organizing all of the entries from AVR's documentation.
*/
void BuildInstructionMap()
{
	AddInstructionToMap((char*)"0000000000000000", 0, 0, l_NOP);
	AddInstructionToMap((char*)"00000001xxxxxxxx", 0, 0, l_MOVW);
	AddInstructionToMap((char*)"00000010xxxxxxxx", 0, 0, l_MULS);
	AddInstructionToMap((char*)"000000110xxx0xxx", 0, 0, l_MULSU);
	AddInstructionToMap((char*)"000000110xxx1xxx", 0, 0, l_FMUL);
	AddInstructionToMap((char*)"000000111xxx0xxx", 0, 0, l_FMULS);
	AddInstructionToMap((char*)"000000111xxx1xxx", 0, 0, l_FMULSU);

	AddInstructionToMap((char*)"000001xxxxxxxxxx", 0, 0, l_CPC);
	AddInstructionToMap((char*)"000101xxxxxxxxxx", 0, 0, l_CP);
	AddInstructionToMap((char*)"000010xxxxxxxxxx", 0, 0, l_SBC);
	AddInstructionToMap((char*)"000110xxxxxxxxxx", 0, 0, l_SUB);
	AddInstructionToMap((char*)"000011xxxxxxxxxx", 0, 0, l_ADD);
	AddInstructionToMap((char*)"000111xxxxxxxxxx", 0, 0, l_ADC);
	AddInstructionToMap((char*)"000100xxxxxxxxxx", 0, 0, l_CPSE);
	AddInstructionToMap((char*)"001000xxxxxxxxxx", 0, 0, l_AND);
	AddInstructionToMap((char*)"001001xxxxxxxxxx", 0, 0, l_EOR);
	AddInstructionToMap((char*)"001010xxxxxxxxxx", 0, 0, l_OR);
	AddInstructionToMap((char*)"001011xxxxxxxxxx", 0, 0, l_MOV);

	AddInstructionToMap((char*)"0011xxxxxxxxxxxx", 0, 0, l_CPI);

	AddInstructionToMap((char*)"0100xxxxxxxxxxxx", 0, 0, l_SBCI);
	AddInstructionToMap((char*)"0101xxxxxxxxxxxx", 0, 0, l_SUBI);
	AddInstructionToMap((char*)"0110xxxxxxxxxxxx", 0, 0, l_ORI);
	AddInstructionToMap((char*)"0111xxxxxxxxxxxx", 0, 0, l_ANDI);

	AddInstructionToMap((char*)"10x0xx0xxxxxxxxx", 0, 0, l_LDD);
	AddInstructionToMap((char*)"10x0xx1xxxxxxxxx", 0, 0, l_STD);

	AddInstructionToMap((char*)"1001000xxxxx0000", 0, 0, l_LDS);
	AddInstructionToMap((char*)"1001001xxxxx0000", 0, 0, l_STS);
	AddInstructionToMap((char*)"1001000xxxxxx001", 0, 0, l_LDPostInc);
	AddInstructionToMap((char*)"1001001xxxxxx001", 0, 0, l_STPostInc);
	AddInstructionToMap((char*)"1001000xxxxxx010", 0, 0, l_LDPreDec);
	AddInstructionToMap((char*)"1001001xxxxxx010", 0, 0, l_STPreDec);
	AddInstructionToMap((char*)"1001000xxxxx0100", 0, 0, l_LPM);
	AddInstructionToMap((char*)"1001000xxxxx0110", 0, 0, l_ELPM);
	AddInstructionToMap((char*)"1001000xxxxx0101", 0, 0, l_LPMPostInc);
	AddInstructionToMap((char*)"1000100xxxxx0111", 0, 0, l_ELPMPostInc);
	AddInstructionToMap((char*)"1001001xxxxx0100", 0, 0, l_XCH);
	AddInstructionToMap((char*)"1001001xxxxx0101", 0, 0, l_LAC);
	AddInstructionToMap((char*)"1001001xxxxx0111", 0, 0, l_LAT);
	AddInstructionToMap((char*)"1001000xxxxx1100", 0, 0, l_LDX);
	AddInstructionToMap((char*)"1001001xxxxx1100", 0, 0, l_STX);
	AddInstructionToMap((char*)"1001000xxxxx1101", 0, 0, l_LDXPostInc);
	AddInstructionToMap((char*)"1001001xxxxx1101", 0, 0, l_STXPostInc);
	AddInstructionToMap((char*)"1001000xxxxx1110", 0, 0, l_LDXPreDec);
	AddInstructionToMap((char*)"1001001xxxxx1110", 0, 0, l_STXPreDec);
	AddInstructionToMap((char*)"1001000xxxxx1111", 0, 0, l_POP);
	AddInstructionToMap((char*)"1001001xxxxx1111", 0, 0, l_PUSH);

	AddInstructionToMap((char*)"1001010xxxxx0000", 0, 0, l_COM);
	AddInstructionToMap((char*)"1001010xxxxx0001", 0, 0, l_NEG);
	AddInstructionToMap((char*)"1001010xxxxx0010", 0, 0, l_SWAP);
	AddInstructionToMap((char*)"1001010xxxxx0011", 0, 0, l_INC);
	AddInstructionToMap((char*)"1001010xxxxx0101", 0, 0, l_ASR);
	AddInstructionToMap((char*)"1001010xxxxx0110", 0, 0, l_LSR);
	AddInstructionToMap((char*)"1001010xxxxx0111", 0, 0, l_ROR);

	AddInstructionToMap((char*)"100101000xxx1000", 0, 0, l_SEB);
	AddInstructionToMap((char*)"100101001xxx1000", 0, 0, l_CLB);

	AddInstructionToMap((char*)"1001010100001000", 0, 0, l_RET);
	AddInstructionToMap((char*)"1001010100011000", 0, 0, l_RETI);
	AddInstructionToMap((char*)"1001010110001000", 0, 0, l_SLEEP);
	AddInstructionToMap((char*)"1001010110011000", 0, 0, l_BREAK);
	AddInstructionToMap((char*)"1001010110101000", 0, 0, l_WDR);
	AddInstructionToMap((char*)"1001010111001000", 0, 0, l_LPM2);
	AddInstructionToMap((char*)"1001010111011000", 0, 0, l_ELPM2);
	AddInstructionToMap((char*)"1001010111101000", 0, 0, l_SPM);
	AddInstructionToMap((char*)"1001010111111000", 0, 0, l_SPMPostInc);

	AddInstructionToMap((char*)"10010100000x1001", 0, 0, l_IJMP);
	AddInstructionToMap((char*)"10010101000x1001", 0, 0, l_ICALL);
	AddInstructionToMap((char*)"1001010xxxxx1010", 0, 0, l_DEC);
	AddInstructionToMap((char*)"10010100xxxx1011", 0, 0, l_DES);
	AddInstructionToMap((char*)"1001010xxxxx110x", 0, 0, l_JMP);
	AddInstructionToMap((char*)"1001010xxxxx111x", 0, 0, l_CALL);

	AddInstructionToMap((char*)"10010110xxxxxxxx", 0, 0, l_ADIW);
	AddInstructionToMap((char*)"10010111xxxxxxxx", 0, 0, l_SBIW);
	AddInstructionToMap((char*)"10011000xxxxxxxx", 0, 0, l_CBI);
	AddInstructionToMap((char*)"10011010xxxxxxxx", 0, 0, l_SBI);
	AddInstructionToMap((char*)"10011001xxxxxxxx", 0, 0, l_SBIC);
	AddInstructionToMap((char*)"10011011xxxxxxxx", 0, 0, l_SBIS);
	AddInstructionToMap((char*)"100111xxxxxxxxxx", 0, 0, l_MUL);

	AddInstructionToMap((char*)"10110xxxxxxxxxxx", 0, 0, l_IN);
	AddInstructionToMap((char*)"10111xxxxxxxxxxx", 0, 0, l_OUT);
	AddInstructionToMap((char*)"1100xxxxxxxxxxxx", 0, 0, l_RJMP);
	AddInstructionToMap((char*)"1101xxxxxxxxxxxx", 0, 0, l_RCALL);
	AddInstructionToMap((char*)"1110xxxxxxxxxxxx", 0, 0, l_LDI);
	AddInstructionToMap((char*)"11110xxxxxxxxxxx", 0, 0, l_CBSR);
	AddInstructionToMap((char*)"1111100xxxxx0xxx", 0, 0, l_BLD);
	AddInstructionToMap((char*)"1111101xxxxx0xxx", 0, 0, l_BST);
	AddInstructionToMap((char*)"1111110xxxxx0xxx", 0, 0, l_SBRC);
	AddInstructionToMap((char*)"1111111xxxxx0xxx", 0, 0, l_SBRS);
}

int main()
{
	BuildInstructionMap();
}
