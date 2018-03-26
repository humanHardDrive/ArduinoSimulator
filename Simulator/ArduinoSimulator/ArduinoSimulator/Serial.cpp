#include "Serial.h"

Serial::Serial()
{

}

unsigned int Serial::available()
{
	return 0;
}

void Serial::begin(unsigned int baudRate, SERIAL_CONFIG config)
{
	this->m_CurrentConfig = config;
	this->m_BaudRate = baudRate;
}

void Serial::begin(unsigned int buadRate)
{
	this->m_CurrentConfig = SERIAL_8N1;
	this->m_BaudRate = buadRate;
}