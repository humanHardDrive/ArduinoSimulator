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
	int ComponentCount = -1;
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
				std::cout << data.cFileName << std::endl;
			}
		} while (FindNextFile(file, &data) != 0);
	}

	return ComponentCount;
}


void ComponentManager::AddComponent(Component& c)
{
	m_ComponentMap[c.GetName()] = c;
}
