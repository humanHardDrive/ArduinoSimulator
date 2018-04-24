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

		void BuildComponentList(std::string path);

		void AddComponent(Component& c);

	private:
		std::map<std::string, Component> m_ComponentMap;
};

