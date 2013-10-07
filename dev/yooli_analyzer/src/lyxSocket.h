#ifndef LYXSOCKET_H
#define LYXSOCKET_H

#include <string>

namespace lyx {

	class Socket {
		protected:
		std::string m_host;
		int m_port;
		int m_sock;

		Socket();
		void print();

		public:
		// Socket(const Socket&);
		Socket(const std::string &h, int p);
		// Socket(const Socket& sockObj);
		virtual ~Socket();
		virtual int send(const void *buf, int len, int flag = 0);
		virtual int recv(void *buf, int len, int flag = 0);
		virtual int rawRecv(void *buf, int len, int flag = 0);
		virtual int setupSocket();

		void test();
	};
}

#endif // LYXSOCKET_H
