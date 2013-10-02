#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <string>
#include <cstring>

using namespace std;

namespace lyx {

	Socket::Socket(const string &h, int p) 
		: m_host(h), m_port(p) { }

	Socket::~Socket() {
		if (m_sock) {
			close(m_sock);
		}
	}


	int Socket::setupSocket() {
		const char *host = m_host.c_str();
#define PORTBUFSIZE__ 8
		char portbuf[PORTBUFSIZE__] = {0};
		sprintf(portbuf, "%d", m_port);
#undef PORTBUFSIZE__
		const char *service = portbuf; 

		// Tell the system what kind(s) of address info we want
		struct addrinfo addrCriteria;                   // Criteria for address match
		memset(&addrCriteria, 0, sizeof(addrCriteria)); // Zero out structure
		addrCriteria.ai_family = AF_UNSPEC;             // v4 or v6 is OK
		addrCriteria.ai_socktype = SOCK_STREAM;         // Only streaming sockets
		addrCriteria.ai_protocol = IPPROTO_TCP;         // Only TCP protocol

		// Get address(es)
		struct addrinfo *servAddr; // Holder for returned list of server addrs
		int rtnVal = getaddrinfo(host, service, &addrCriteria, &servAddr);
		if (rtnVal != 0) {
			printf("getaddrinfo() failed");
			return -1;
		}

		m_sock = -1;
		for (struct addrinfo *addr = servAddr; addr != NULL; addr = addr->ai_next) {
			// Create a reliable, stream socket using TCP
			m_sock = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
			if (m_sock < 0)
				continue;  // Socket creation failed; try next address

			// Establish the connection to the echo server
			if (connect(m_sock, addr->ai_addr, addr->ai_addrlen) == 0)
				break;     // Socket connection succeeded; break and return socket

			close(m_sock); // Socket connection failed; try next address
			m_sock = -1;
		}

		freeaddrinfo(servAddr); // Free addrinfo allocated in getaddrinfo()
		return 0;
	}
} // namespace lyx
