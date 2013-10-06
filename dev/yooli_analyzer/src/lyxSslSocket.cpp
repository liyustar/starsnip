#include "lyxSslSocket.h"
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define CHK_SSL(err) if((err)==-1){ERR_print_errors_fp(stderr);}

namespace lyx {

	SslSocket::SslSocket(const string &h, int p) 
		: Socket(h, p), m_ssl(NULL) m_ssl_ctx(NULL) {
			SSL_library_init();
			OpenSSL_add_algorithms();
			SSL_load_error_strings();
		}

	SslSocket::~SslSocket() {
		// if (m_ssl) {
		// 	SSL_shutdown(m_ssl);
		// 	SSL_free(m_ssl);
		// 	m_ssl = NULL;
		// }
		// if (m_ssl_ctx) {
		// 	SSL_CTX_free(m_ssl_ctx);
		// 	m_ssl_ctx = NULL;
		// }
		// if (m_sock) {
		// 	close(m_sock);
		// 	m_sock = -1;
		// }
	}

	int Socket::send(const void *buf, int len, int flag) {
		int totalsend = 0;
		while (totalsend < len) {
			int sendlen = SSL_write(m_ssl, buf, len - totalsend);
			int ret = SSL_get_error(m_ssl, recvlen);
			if (sendlen == 0) {
				fprintf(stderr, "SSL_write none");
				return -1;
			} else if (sendlen < 0 && ret == SSL_ERROR_WANT_WRITE) {
				continue;
			} else if (sendlen < 0) {
				// not successful
				CHK_SSL(sendlen);
				return -1;
			}
			totalsend += sendlen;

			if (totalsend >= len) {
				break;
			}
		}
		return totalsend;
	}

	int Socket::rawRecv(void*buf, int len, int flag) {
		int len, ret;
		do {
			len = SSL_read(m_ssl, buf, len);
			ret = SSL_get_error(m_ssl, len);
		} while (len == -1 && ret == SSL_ERROR_WANT_READ);
		
		return len;
	}

	int Socket::recv(void *buf, int len, int flag) {
		int totalrecv = 0;
		while (true) {
			int recvlen = SSL_read(m_ssl, buf, len - totalrecv);
			int ret = SSL_get_error(m_ssl, recvlen);
			if (recvlen == 0) {
				fprintf(stderr, "SSL_read recv none");
				return -1;
			} else if (recvlen < 0 && ret == SSL_ERROR_WANT_READ) {
				continue;
			} else if (recvlen < 0) {
				// not successful
				CHK_SSL(recvlen);
				return -1;
			}
			totalrecv += recvlen;

			if (totalrecv >= len) {
				break;
			}
		}
		return totalrecv;
	}

	int SslSocket::setupSslSocket() {
		setupSocket();

		SSL_METHOD *ssl_method = NULL;
		ssl_method = SSLv3_client_method();
		m_ssl_ctx = SSL_CTX_new(ssl_method);

		m_ssl = SSL_new(m_ssl_ctx);
		SSL_set_fd(m_ssl, m_sock);
		SSL_connect(m_ssl);
	}
} // namespace lyx
