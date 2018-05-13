#pragma once
#include <string>
#include <vector>

class GenericHardware
{
	public:
		GenericHardware();
		GenericHardware(std::string name, std::string component);
		~GenericHardware();

		enum PIN_DIR
		{
			INPUT = 0,
			OUTPUT,
			HI_Z
		};

		void SetPinCount(unsigned int count) { this->m_PinCount = count; }

		std::string GetName() { return this->m_Name; }
		std::string GetComponent() { return this->m_Component; }
		int GetPinCount() { return this->m_PinCount; }

	private:
		std::string m_Name;
		std::string m_Component;

		unsigned int m_PinCount;
		std::vector<PIN_DIR> m_PinDir;
};

