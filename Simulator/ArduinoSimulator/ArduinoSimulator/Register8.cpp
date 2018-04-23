#include "Register8.h"

Register8::Register8(uint8_t ResetValue)
{
	this->value = ResetValue;
	this->m_OnChange = NULL;
}

Register8::~Register8()
{}

void Register8::SetOnChange(void(*OnChange)(Register8 *reg))
{
	this->m_OnChange = OnChange;
}

Register8 & Register8::operator=(const uint8_t & v)
{
	if (this->value != v)
	{
		this->value = v;

		if (this->m_OnChange)
			this->m_OnChange(this);
	}

	return *this;
}

uint8_t Register8::operator^(const uint8_t & v)
{
	return (this->value ^ v);
}

uint8_t Register8::operator&(const uint8_t & v)
{
	return (this->value & v);
}

uint8_t Register8::operator|(const uint8_t & v)
{
	return (this->value | v);
}

uint8_t Register8::operator~()
{
	return ~this->value;
}

Register8 & Register8::operator^=(const uint8_t rhs)
{
	this->value ^= rhs;
	return *this;
}

bool Register8::operator!()
{
	return (this->value != 0);
}

bool Register8::operator&&(const Register8 & rhs)
{
	return false;
}

bool Register8::operator||(const Register8 & rhs)
{
	return false;
}
