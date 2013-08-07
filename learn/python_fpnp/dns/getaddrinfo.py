#!/bin/env python

import sys, socket

domain = sys.argv[1]

# get the ipaddr
result = socket.getaddrinfo(domain, None)
print result[0][4]
print result #[0][4]
