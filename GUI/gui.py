import sys
import os
from graphics import *
import modulelistbuilder as mlb

ResourcePath = 'resources\\'

def LoadModules(list):
	ImportList = dict()
	for module in list:
		ModuleName = list[module].type
		ModuleName = ModuleName.replace(' ', '_')
		ImportList[ModuleName] = __import__(ModuleName)
		print ImportList[ModuleName].GetModuleName()

def main():
	ModuleList = mlb.BuildModuleList(ResourcePath)
	sys.path.append(os.getcwd() + '\\' + ResourcePath)
	win = GraphWin('Hardware Simulator', 640, 480)
	LoadModules(ModuleList)
	
	win.getMouse()
	win.close()

main()