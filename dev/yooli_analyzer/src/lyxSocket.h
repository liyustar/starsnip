#ifndef LYXSOCKET_H
#define LYXSOCKET_H

#include <string>

namespace lyx {

	class Socket {
		private:
		std::string m_host;
		int m_port;
		int m_sock;

		Socket();
		Socket(const Socket&);
		void print();

		public:
		Socket(const std::string &h, int p);
		// Socket(const Socket& sockObj);
		~Socket();
		int send(const void *buf, int len, int flag = 0);
		int recv(void *buf, int len, int flag = 0);
		int setupSocket();

		void test();
	};
}

#endif // LYXSOCKET_H
