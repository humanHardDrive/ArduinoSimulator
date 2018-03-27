#pragma once

#include <string>

class Client
{
	public:
		Client(std::string name);

		void begin();

	private:
		std::string m_Name;
};