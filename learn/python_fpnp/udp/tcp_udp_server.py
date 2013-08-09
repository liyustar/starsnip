
from threading import *
from socket import *
import os

UDPSERVENABLE = True
TCPSERVENABLE = True

BUFSIZE	= 10240
PORT	= 8888
ADDR	= ('', PORT)

class UdpServThread(Thread):		
	def run(self):
		sock = socket(AF_INET, SOCK_DGRAM)
		sock.bind(ADDR)
		while True:
			data, addr = sock.recvfrom(BUFSIZE)
			print('udp recv data\'s len is %d from %s' % (len(data), addr))
			sock.sendto(data, addr)
			
class TcpClnt(Thread):
	def __init__(self, sock, addr):
		Thread.__init__(self)
		self.sock = sock
		self.addr = addr
	def run(self):
		data = sock.recv(BUFSIZE)
		print('tcp recv data\'s len is %d' % len(data))
		sock.send(data)
		
class TcpServThread(Thread): 		
	def run(self):
		sock = socket(AF_INET, SOCK_STREAM)
		sock.bind(ADDR)
		sock.listen(10)
		while True:
			csock, caddr = sock.accept()
			print('tcp accept: %s %s' % (csock.getsockname(), csock.getpeername()))
			clnt = TcpClnt(csock, caddr)
			clnt.start()
		

if UDPSERVENABLE:
	udpServ = UdpServThread()
	udpServ.start()
	print 'udp server start, wait data...'
if TCPSERVENABLE:
	tcpServ = TcpServThread()
	tcpServ.start()
	print 'tcp server start, wait data...'







