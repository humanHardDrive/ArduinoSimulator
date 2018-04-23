#pragma once
#include <cstdint>

class Register16
{
public:
	Register16(uint16_t ResetValue);
	~Register16();

	Register16& operator=(const uint16_t& v);

	void SetOnChange(void(*OnChange)(Register16* reg));

	private:
		void(*m_OnChange)(Register16* reg);

	public:
		uint16_t value;
};

