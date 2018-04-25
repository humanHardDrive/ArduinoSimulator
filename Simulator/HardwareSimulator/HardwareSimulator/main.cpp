#include <iostream>
#include <thread>

#include <stdlib.h>
#include <stdio.h>
#include <direct.h>

#include "Connection.h"
#include "Server.h"

#include "ComponentManager.h"

#include "Python.h"

static void msghandler(char* msg, size_t size, Client* c)
{
	std::string smsg(msg, size);

	printf("%d says: %s\n", c->socket(), smsg.c_str());
}

int main(int argc, char** argv)
{
	char curdir[256];
	std::string respath;

	Server Arduino0("127.0.0.1", "4040", 10);
	Arduino0.SetMsgHandler(msghandler);

	_getcwd(curdir, sizeof(curdir));
	respath.append(curdir);
	respath.append("\\..\\..\\..\\resources");
	ComponentManager cManager;

	Py_Initialize();

	cManager.BuildComponentList(respath);

	Arduino0.start();
	while (1);

	Py_Finalize();

	return 0;
}