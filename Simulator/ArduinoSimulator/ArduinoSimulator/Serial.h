#pragma once

#include <cstdint>
#include <string>

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

		void print(char c);
		void print(char* str);
		void print(std::string str);
		void print(int num);
		void print(double num);
		void print(float num);

		void println(char c);
		void println(char* str);
		void println(std::string str);
		void println(int num);
		void println(double num);
		void println(float num);
	private:
		unsigned int m_BaudRate;
		SERIAL_CONFIG m_CurrentConfig;
};