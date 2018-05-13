#pragma once
#include <map>
#include <string>

#include "rapidxml.hpp"

#include "GenericHardware.h"

class ComponentManager
{
	public:
		ComponentManager();
		~ComponentManager();

		int BuildComponentList(std::string path);

		void AddComponent(GenericHardware& c);
		GenericHardware& BuildHardware(std::string path, std::string component);

	private:
		std::string m_ResourcePath;

		std::map<std::string, GenericHardware> m_ComponentMap;
		std::string m_XMLData; //this needs to be kept for rapidxml
};

