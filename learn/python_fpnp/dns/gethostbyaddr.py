#!/usr/bin/env python

# usage: ./gethostbyaddr.py 74.125.128.99

import sys, socket

ip = sys.argv[1]

try:
	result = socket.gethostbyaddr(ip)
	print 'Primary hostname:'
	print ' ' + result[0]

# Display the list of available addressed that is also returned
	print '\nAddress:'
	for item in result[2]:
		print ' ' + item
except socket.herro, e:
	print "Couldn't look up name:", e


