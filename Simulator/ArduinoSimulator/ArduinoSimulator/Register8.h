#pragma once
#include <cstdint>

class Register8
{
	public:
		Register8(uint8_t ResetValue);
		~Register8();

		Register8& operator=(const uint8_t& v);

		void SetOnChange(void(*OnChange)(Register8* reg));

	private:
		void(*m_OnChange)(Register8* reg);

	private:
		uint8_t value;
};

