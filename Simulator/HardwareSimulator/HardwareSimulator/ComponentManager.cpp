#include "ComponentManager.h"

#include <fstream>
#include <Windows.h>
#include <iostream>

#include <cstring>

ComponentManager::ComponentManager()
{
}

ComponentManager::~ComponentManager()
{
}


int ComponentManager::BuildComponentList(std::string path)
{
	int ComponentCount = 0;
	std::string SearchPath(path);
	WIN32_FIND_DATA data;
	HANDLE file;

	SearchPath.append("\\*");

	if ((file = FindFirstFile(SearchPath.c_str(), &data)) != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (strstr(data.cFileName, ".xml"))
			{
				std::string ComponentName(data.cFileName);
				ComponentName = ComponentName.substr(0, ComponentName.find_last_of("."));

				AddComponent(BuildHardware(path, ComponentName));
				ComponentCount++;
			}
		} while (FindNextFile(file, &data) != 0);
	}

	return ComponentCount;
}


void ComponentManager::AddComponent(GenericHardware& c)
{
	m_ComponentMap[c.GetComponent()] = c;
}

GenericHardware& ComponentManager::BuildHardware(std::string path, std::string component)
{
	std::string CatPath = path.append("\\");
	CatPath.append(component);
	CatPath.append(".xml");
	GenericHardware Hardware;

	std::ifstream ComponentRes(CatPath);

	if (ComponentRes.is_open())
	{
		std::cout << "File open" << std::endl;
	}

	return Hardware;
}