import os
import xml.etree.ElementTree as ET

class Module:
	def __init__(self, type):
		self.type = type
		
	def SetResourcePath(self, path):
		self.resourcepath = path

def BuildModule(path):
	tree = ET.parse(path)
	root = tree.getroot();

	m = Module(root.attrib.get('name'))
	m.SetResourcePath(root.find('image').attrib.get('path'))
	return m


def BuildModuleList(path):
	modules = dict()

	for file in os.listdir(path):
		if(file.endswith('.xml')):
			m = BuildModule(path + file)
			
			if(m.type not in modules):
				modules[m.type] = m
			else:
				print 'Duplicate ' + m.type + ' \"' + file + '\"'
				
	return modules