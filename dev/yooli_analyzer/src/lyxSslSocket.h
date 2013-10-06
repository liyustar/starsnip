#ifndef LYXSSLSOCKET_H
#define LYXSSLSOCKET_H

#include "lyxSocket.h"
#include "openssl/ssl.h"
#include <string>

namespace lyx {

	class SslSocket : public Socket{
		private:
		SSL *m_ssl;
		SSL_CTX *m_ssl_ctx;

		SslSocket();
		void print();

		public:
		// SslSocket(const SslSocket&);
		SslSocket(const std::string &h, int p);
		// SslSocket(const SslSocket& sockObj);
		~SslSocket();
		int send(const void *buf, int len, int flag = 0);
		int recv(void *buf, int len, int flag = 0);
		int rawRecv(void *buf, int len, int flag = 0);
		int setupSslSocket();

		void test();
	};
}

#endif // LYXSSLSOCKET_H
