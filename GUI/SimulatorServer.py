import threading
import socket

BUFFER_SIZE = 1024

StopServer = False
ConnectionsActive = 0
ClientLock = threading.Lock()

class ServerThread(threading.Thread):
   def __init__(self, listener):
      threading.Thread.__init__(self)
      self.listener = listener
	  
   def run(self):
	ServerListenerThread(self.listener)
	 
	 
class ClientThread (threading.Thread):
	def __init__(self, client, clientaddress):
		threading.Thread.__init__(self)
		self.client = client
		self.address = clientaddress
		
	def run(self):
		ClientThreadProcess(self.client, self.address)
	
	
ActiveServer = ServerThread(0)
	
def StartServer(ip, port):
	print 'Starting server...'
	print ''
	
	global ActiveServer
	global StopServer
	
	listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	listener.settimeout(2)
	listener.bind((ip, port))
	listener.listen(32)
	
	StopServer = False;
	ActiveServer = ServerThread(listener)
	ActiveServer.start()
	
	
def KillServer():	
	global ConnectionsActive
	global StopServer
	global ActiveServer
	
	StopServer = True
	
	print 'Waiting for server to end...'
	print ''
	ActiveServer.join()
	
	
def ServerListenerThread(listener):
	print 'Starting listener...'
	print ''
	
	global ConnectionsActive
	global StopServer
	
	while not StopServer:
		try:
			client, clientaddress = listener.accept()
		
			cthread = ClientThread(client, clientaddress)
			cthread.start()
		except socket.timeout:
			pass
		
	print 'Waiting for connections to end...'
	print ''
	while ConnectionsActive > 0:
		pass
		
	print 'Server closed'
	print ''
	listener.close()
	
	
def ClientThreadProcess(client, address):
	print 'New client ' + address[0]
	print ''

	global ConnectionsActive
	global StopServer
	
	ClientLock.acquire()
	ConnectionsActive = ConnectionsActive + 1
	ClientLock.release()
	
	ConnectionAlive = True
	while (not StopServer) and ConnectionAlive:
		try:
			data = client.recv(BUFFER_SIZE)
			print address[0] + ': ' + data
			
			if not data:
				break
		except socket.error:
			pass
		
	client.close()	
	
	ClientLock.acquire()
	print 'Closed connection to ' + address[0]
	ConnectionsActive = ConnectionsActive - 1
	ClientLock.release()