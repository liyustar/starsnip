#!/usr/bin/env python
# Foundations of Python Network Programming - Chapter 2 - udp_local.py
# UDP client and server on localhost

import socket, sys

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

MAX = 65535
PORT = 1066

if True:
	s.bind(('127.0.0.1', PORT))
	while True:
		data, address = s.recvfrom(MAX)
		print 'The client at', address, 'says', repr(data)
		s.sendto('Your data was %d bytes' % len(data), address)
		
else:
	print >> sys.stderr, 'usage: udp_local.py server|client'