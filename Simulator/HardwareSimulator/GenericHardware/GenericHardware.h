#pragma once

#include <string>

class GenericHardware
{
public:
	GenericHardware(std::string name);

protected:
	std::string m_Name;
};