#pragma once

#include <cstdint>

enum SERIAL_CONFIG
{
	SERIAL_5N1 = 0,
	SERIAL_6N1,
	SERIAL_7N1,
	SERIAL_8N1,
	SERIAL_5N2,
	SERIAL_6N2,
	SERIAL_7N2,
	SERIAL_8N2,
	SERIAL_5E1,
	SERIAL_6E1,
	SERIAL_7E1,
	SERIAL_8E1,
	SERIAL_5E2,
	SERIAL_6E2,
	SERIAL_7E2,
	SERIAL_8E2,
	SERIAL_5O1,
	SERIAL_6O1,
	SERIAL_7O1,
	SERIAL_8O1,
	SERIAL_5O2,
	SERIAL_6O2,
	SERIAL_7O2,
	SERIAL_8O2
};

class Serial
{
	public:
		Serial();
		
		unsigned int available();

		void begin(unsigned int buadRate, SERIAL_CONFIG config);
		void begin(unsigned int buadRate);

	private:
		unsigned int m_BaudRate;
		SERIAL_CONFIG m_CurrentConfig;
};