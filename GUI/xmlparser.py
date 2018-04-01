import xml.etree.ElementTree as ET

tree = ET.parse('..\\config.xml')
root = tree.getroot()

hardware_devices = root.find('Hardware').findall('device')
for device in hardware_devices:
	device_attrib = device.attrib
	device_draw = device.find('draw').attrib
	device_connections = device.find('connections').findall('connection')
	
	print device_attrib.get('name') + ' (' + device_attrib.get('type') + ')'
	print 'Draw (' + device_draw.get('x') + ',' + device_draw.get('y') + ')'
	
	if(len(device_connections) > 0):
		print 'Connections'
		for connection in device_connections:
			from_pin = connection.find('from').attrib.get('pin')
			to_pin = connection.find('to').attrib.get('pin')
			to_device = connection.find('to').attrib.get('device')
			print '\tPin ' + from_pin + ' to Pin ' + to_pin + ' on ' + to_device
	
	print ''