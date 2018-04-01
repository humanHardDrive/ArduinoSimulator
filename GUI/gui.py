import sys
import os

from graphics import *

import modulelistbuilder as mlb
import hardwarelistbuilder as hlb

import thread
import socket

ResourcePath = 'resources\\'
ConfigPath = '..\config.xml'

SERVER_IP = '127.0.0.1'
TCP_PORT = 8080
BUFFER_SIZE = 1024

Version_Minor = 0
Version_Major = 0

def LoadModules(list):
	print 'Loading Modules...'
	for module in list:
		ModuleName = list[module].type
		ModuleName = ModuleName.replace(' ', '_')
		
		print 'Found ' + list[module].type + ' (' + ModuleName + ')'
		
		list[module].SetImport(__import__(ModuleName))
		
	print ''

def DrawHardware(HardwareList, window):
	print 'Banana'
	
def DrawConnections(HardwareList, window):
	print 'Banana'
	
def StartServer(ip, port):
	print 'Starting server...'
	print ''
	
	listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((TCP_IP, TCP_PORT))
	s.listen(32)
	
	thread.start_new_thread(ServerListenerThread, (listener))
	
	
def ServerListenerThread(listener):
	print 'Starting listener...'
	print ''
	
	while 1:
		client, clientaddress = listener.accept()
		thread.start_new_thread(ClientThread, (client, clientaddress))
	
	
def ClientThread(client, address):
	print 'New client ' + address
	
	
def main():
	print 'Simulator GUI v' + str(Version_Major) + '.' + str(Version_Minor)
	
	ModuleList = mlb.BuildModuleList(ResourcePath)
	sys.path.append(os.getcwd() + '\\' + ResourcePath)
	LoadModules(ModuleList)
	HardwareList = hlb.BuildHardwareList(ConfigPath, ModuleList)
	hlb.ValidateConnections(HardwareList)
	
	win = GraphWin('Hardware Simulator', 640, 480)
	
	win.getMouse()
	win.close()

main()