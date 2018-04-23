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
