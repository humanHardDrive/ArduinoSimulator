#pragma once
#include <cstdint>
#include <string>

class Register8
{
	public:
		Register8(std::string name, uint8_t ResetValue, bool readonly);
		~Register8();

		Register8& operator=(const uint8_t& v);
		uint8_t operator^(const uint8_t& v);
		uint8_t operator&(const uint8_t& v);
		uint8_t operator|(const uint8_t& v);
		uint8_t operator~();

		Register8& operator^=(const uint8_t rhs);
		Register8& operator|=(const uint8_t rhs);
		Register8& operator&=(const uint8_t rhs);

		bool operator!();
		bool operator&&(const Register8& rhs);
		bool operator||(const Register8& rhs);
		
		void SetOnChange(void(*OnChange)(Register8* reg));

	private:
		void(*m_OnChange)(Register8* reg);

	public:
		uint8_t value;
		std::string name;
		bool readonly;
};

