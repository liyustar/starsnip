#!/bin/env python

# usage: ./getaddrinfo.py www.google.com

import sys, socket

domain = sys.argv[1]

# get the ipaddr
result = socket.getaddrinfo(domain, None)
# print result[0][4]

counter = 0
for item in result:
	print '%-2d:%s' % (counter, item[4])
	counter += 1

