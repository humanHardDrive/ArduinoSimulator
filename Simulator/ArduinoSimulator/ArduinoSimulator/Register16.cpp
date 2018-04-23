#include "Register16.h"

Register16::Register16(uint16_t ResetValue)
{
	this->value = ResetValue;
	this->m_OnChange = NULL;
}


Register16::~Register16()
{
}

void Register16::SetOnChange(void(*OnChange)(Register16 *reg))
{
	this->m_OnChange = OnChange;
}

Register16& Register16::operator=(const uint16_t & v)
{
	if (this->value != v)
	{
		this->value = v;

		if (this->m_OnChange)
			this->m_OnChange(this);
	}

	return *this;
}
