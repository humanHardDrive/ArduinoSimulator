import os
import xml.etree.ElementTree as ET

class Hardware:
	def __init__(self, name, type):
		self.type = type
		self.name = name
		self.connections = []
		self.x = 0
		self.y = 0
		
	def SetCoord(self, x, y, angle):
		self.x = x
		self.y = y
		self.angle = angle
		
	def AddConnection(self, me, them, device):
		self.connections.append([me, them, device])
		

def BuildHardwareList(path, ModuleList):
	hardware = dict()
	tree = ET.parse(path)
	root = tree.getroot()
	
	print 'Building hardware list...'
	
	hardware_devices = root.find('Hardware').findall('device')
	for device in hardware_devices:
		device_name = device.attrib.get('name')
		device_type = device.attrib.get('type').replace(' ','_')
		h = []
		
		if(device_type not in ModuleList):
			print 'Device ' + device_type + ' not found'
		else:
			h = Hardware(device_name, device_type)
			print 'Hardware found ' + device_name + ' (' + device_type + ')'
		
		device_draw = device.find('draw').attrib
		
		h.SetCoord(int(device_draw.get('x')), int(device_draw.get('y')), int(device_draw.get('angle')))
		
		device_connections = device.find('connections').findall('connection')
		
		if(len(device_connections) > 0):
			for connection in device_connections:
				from_pin = connection.find('from').attrib.get('pin')
				to_pin = connection.find('to').attrib.get('pin')
				to_device = connection.find('to').attrib.get('device')
				
				h.AddConnection(from_pin, to_pin, to_device)
		
		if(h.name not in hardware):
			hardware[h.name] = h
		else:
			print 'Duplicate Hardware ' + h.name
		
	print ''
	return hardware
	
def ValidateConnections(HardwareList):
	print 'Validating hardware...'
	AllConnectionsValid = True
	
	for HardwareName in HardwareList:
		hardware = HardwareList[HardwareName]
		print HardwareName + ': ' + str(len(hardware.connections)) + ' connections'
		for connection in hardware.connections:
			valid = True
			NotValidReason = ''
			if(connection[2] not in HardwareList):
				valid = False
				AllConnectionsValid = False
				NotValidReason = 'Undefined device'
			elif(HardwareName == connection[2] and connection[0] == connection[1]):
				valid = False
				AllConnectionsValid = False
				NotValidReason = 'Connected to self'
			
			print HardwareName + '[' + connection[0] + '] -> ' + connection[2] + '[' + connection[1] + ']\tValid=' + str(valid) + ' ' + NotValidReason
	
	print ''
	return AllConnectionsValid