import random, socket, sys

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

MAX = 65535
PORT = 1060

# if 2 <= len(sys.argv) <= 3 and sys.argv[1] == 'server':
if True:
	# interface = sys.argv[2] if len(sys.argv) > 2 else ''
	interface = ''
	s.bind((interface, PORT))
	print 'Listening at', s.getsockname()
	while True:
		data, address = s.recvfrom(MAX)
		if random.randint(0, 1):
			print 'The client at', address, 'says:', repr(data)
			# s.sendto('Your data was %d bytes' % len(data), address)
		else:
			print 'Pretending to drop packet from', address
			
else:
	print >> sys.stderr, 'usage: udp_remote_serv.py server [ <interface> ]'
	print >> sys.stderr, '   or: udp_remote_clnt.py client <host>'
	sys.exit(2)