import sys
import os
from graphics import *
import modulelistbuilder as mlb
import hardwarelistbuilder as hlb

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

def main():
	print 'Simulator GUI v' + str(Version_Major) + '.' + str(Version_Minor)
	
	ModuleList = mlb.BuildModuleList(ResourcePath)
	sys.path.append(os.getcwd() + '\\' + ResourcePath)
	LoadModules(ModuleList)
	HardwareList = hlb.BuildHardwareList(ConfigPath, ModuleList)
	
	win = GraphWin('Hardware Simulator', 640, 480)
	
	win.getMouse()
	win.close()

main()