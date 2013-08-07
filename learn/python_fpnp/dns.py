import socket

hostname = 'localhost'
addr = socket.gethostbyname(hostname)
print 'The address of ', hostname, 'is', addr
