#include <iostream>
#include <thread>

#include "rapidxml.hpp"

#include "Connection.h"
#include "Server.h"

#include "Python.h"

static void msghandler(char* msg, size_t size, Client* c)
{
	std::string smsg(msg, size);

	printf("%d says: %s\n", c->socket(), smsg.c_str());
}

int main(int argc, char** argv)
{
	Server Arduino0("127.0.0.1", "4040", 10);
	Arduino0.SetMsgHandler(msghandler);

	Py_Initialize();

	Arduino0.start();
	while (1);

	Py_Finalize();

	return 0;
}