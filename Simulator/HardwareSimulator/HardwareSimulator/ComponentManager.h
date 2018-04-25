#pragma once
#include <map>
#include <string>

#include "rapidxml.hpp"

#include "Component.h"

class ComponentManager
{
	public:
		ComponentManager();
		~ComponentManager();

		int BuildComponentList(std::string path);

		void AddComponent(Component& c);

	private:
		std::map<std::string, Component> m_ComponentMap;
		std::string m_XMLData; //this needs to be kept for rapidxml
};

