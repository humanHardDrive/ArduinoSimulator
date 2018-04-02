import sys
import os

from graphics import *

import modulelistbuilder as mlb
import hardwarelistbuilder as hlb

import thread
import threading
import socket

ResourcePath = 'resources\\'
ConfigPath = '..\config.xml'

SERVER_IP = '127.0.0.1'
TCP_PORT = 8080
BUFFER_SIZE = 1024

Version_Minor = 0
Version_Major = 0

StopServer = False
ConnectionsActive = 0
ClientLock = threading.Lock()

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
	listener.bind((ip, port))
	listener.listen(32)
	
	return thread.start_new_thread(ServerListenerThread, (listener,))
	
	
def ServerListenerThread(listener):
	print 'Starting listener...'
	print ''
	
	global ConnectionsActive
	global StopServer
	
	while not StopServer:
		client, clientaddress = listener.accept()
		thread.start_new_thread(ClientThread, (client, clientaddress, ))
		
	print 'Waiting for connections to end...'
	print ''
	while ConnectionsActive > 0:
		pass
		
	print 'Server closed'
	print ''
	listener.close()
	
	
def ClientThread(client, address):
	print 'New client ' + address[0]
	print ''

	global ConnectionsActive
	global StopServer
	
	ClientLock.acquire()
	ConnectionsActive = ConnectionsActive + 1
	ClientLock.release()
	
	while not StopServer:
		data = client.recv(BUFFER_SIZE)
		print address[0] + ':' + data
		
	client.close()	
	
	ClientLock.acquire()
	ConnectionsActive = ConnectionsActive - 1
	ClientLock.release()
		
	
def main():
	print 'Simulator GUI v' + str(Version_Major) + '.' + str(Version_Minor)
	print ''
	
	ModuleList = mlb.BuildModuleList(ResourcePath)
	sys.path.append(os.getcwd() + '\\' + ResourcePath)
	LoadModules(ModuleList)
	HardwareList = hlb.BuildHardwareList(ConfigPath, ModuleList)
	hlb.ValidateConnections(HardwareList)
	
	ServerThread = StartServer('127.0.0.1', 8080)
	
	win = GraphWin('Hardware Simulator', 640, 480)
	
	win.getMouse()
	win.close()

	StopServer = True
	ServerThread.join()
	
main()