#include "ComponentManager.h"

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}


void ComponentManager::BuildComponentList(std::string path)
{

}


void ComponentManager::AddComponent(Component& c)
{
	m_ComponentMap[c.GetName()] = c;
}
