import os
import xml.etree.ElementTree as ET

class Hardware:
	def __init__(self, name, type):
		self.type = type
		self.connections = []
		

def BuildHardwareList(path, ModuleList):
	hardware = dict()
	tree = ET.parse(path)
	root = tree.getroot()
	
	hardware_devices = root.find('Hardware').findall('device')
	for device in hardware_devices:
		device_name = device.attrib.get('name')
		device_type = device.attrib.get('type').replace(' ','_')
		h = []
		
		if(device_type not in ModuleList):
			print 'Device ' + device_type + ' not found'
		else:
			h = Hardware(device_name, device_type)
		
		device_draw = device.find('draw').attrib
		device_connections = device.find('connections').findall('connection')
		
		if(len(device_connections) > 0):
			print 'Connections'
			for connection in device_connections:
				from_pin = connection.find('from').attrib.get('pin')
				to_pin = connection.find('to').attrib.get('pin')
				to_device = connection.find('to').attrib.get('device')
				print '\tPin ' + from_pin + ' to Pin ' + to_pin + ' on ' + to_device
		
		print ''
				
	return hardware
	
def ValidateConnections():
	print 'Banana'