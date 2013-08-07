import socket, sys

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

MAX = 65535
PORT = 1060

# if len(sys.argv) == 3 and sys.argv[1] == 'client':
if True:
	hostname = 'localhost'
	s.connect((hostname, PORT))
	print 'Client socket name is', s.getsockname()
	delay = 0.1
	while True:
		s.send('This is another message')
		print 'Waiting up to', delay, 'seconds for a reply'
		s.settimeout(delay)
		try:
			data = s.recv(MAX)
		except socket.timeout:
			delay *= 2	# wait even longer for the next request
			if delay > 2.0:
				raise RuntimeError('I think the server is down')
		except:
			raise	# a real error, so we let the user see it
		else:
			break	# we are done, and can stop looping
			
	print 'The server says', repr(data)

else:
	print >> sys.stderr, 'usage: udp_remote_serv.py server [ <interface> ]'
	print >> sys.stderr, '   or: udp_remote_clnt.py client <host>'
	sys.exit(2)