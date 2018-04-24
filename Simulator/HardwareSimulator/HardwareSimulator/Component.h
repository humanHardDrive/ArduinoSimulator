#pragma once
#include <string>

class Component
{
	public:
		Component();
		~Component();

		std::string GetName();

	private:
		std::string m_Name;
};

