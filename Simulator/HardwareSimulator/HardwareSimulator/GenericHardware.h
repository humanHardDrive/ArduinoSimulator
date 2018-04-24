#pragma once
#include <string>

class GenericHardware
{
	public:
		GenericHardware();
		~GenericHardware();

		enum PIN_DIR
		{
			INPUT = 0,
			OUTPUT,
			HI_Z
		};

	private:
		std::string m_Name;
		std::string m_Component;

		unsigned int m_PinCount;
};

