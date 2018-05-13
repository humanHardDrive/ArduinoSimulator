#include "GenericHardware.h"

GenericHardware::GenericHardware()
{
}

GenericHardware::GenericHardware(std::string name, std::string component)
{
	this->m_Name = name;
	this->m_Component = component;

	this->m_PinCount = 0;
}

GenericHardware::~GenericHardware()
{
}
