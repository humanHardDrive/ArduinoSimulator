import sys
import os

from graphics import *

import modulelistbuilder as mlb
import hardwarelistbuilder as hlb
import SimulatorServer

ResourcePath = 'resources\\'
ConfigPath = '..\config.xml'

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
		
	
def main():
	print 'Simulator GUI v' + str(Version_Major) + '.' + str(Version_Minor)
	print ''
	
	ModuleList = mlb.BuildModuleList(ResourcePath)
	sys.path.append(os.getcwd() + '\\' + ResourcePath)
	LoadModules(ModuleList)
	HardwareList = hlb.BuildHardwareList(ConfigPath, ModuleList)
	hlb.ValidateConnections(HardwareList)
	
	SimulatorServer.StartServer('127.0.0.1', 8080)
	
	win = GraphWin('Hardware Simulator', 640, 480)
	
	win.getMouse()
	win.close()
	
	SimulatorServer.KillServer()
	
main()