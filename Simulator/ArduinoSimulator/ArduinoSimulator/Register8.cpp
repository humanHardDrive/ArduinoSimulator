#include "Register8.h"

Register8::Register8(std::string name, uint8_t ResetValue, bool readonly)
{
	this->value = ResetValue;
	this->name = name;
	this->readonly = readonly;

	this->m_OnChange = NULL;
}

Register8::~Register8()
{}

void Register8::SetOnChange(void(*OnChange)(Register8 *reg))
{
	this->m_OnChange = OnChange;
}

Register8& Register8::operator=(const uint8_t & v)
{
	if (!this->readonly)
	{
		if (this->value != v)
		{
			this->value = v;

			if (this->m_OnChange)
				this->m_OnChange(this);
		}
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

Register8& Register8::operator^=(const uint8_t rhs)
{
	return this->operator=(this->value ^ rhs);
}

Register8& Register8::operator|=(const uint8_t rhs)
{
	return this->operator=(this->value | rhs);
}

Register8& Register8::operator&=(const uint8_t rhs)
{
	return this->operator=(this->value & rhs);
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
