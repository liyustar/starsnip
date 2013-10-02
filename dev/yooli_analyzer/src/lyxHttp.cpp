#include "lyxHttp.h"
#include "lyxUrl.h"
#include "lyxSocket.h"
#include <string>

using namespace std;

namespace lyx {

	Http::Http() {
	}

	Http::Http(const Http& httpObj) {
		*this = httpObj;
	}

	// void print();

	Http::Http(Url url) {
		m_url = url;
	}

	Http::~Http() {}

	int Http::setMethod(string methodStr) {
		if (methodStr.compare("GET") == 0
			|| methodStr.compare("get") == 0) {
			m_method = METHOD_GET;
		} else if (methodStr.compare("POST") == 0
					|| methodStr.compare("post") == 0) {
			m_method = METHOD_POST;
		} else {
			m_method = METHOD_UNKNOW;
		}
	}

	string Http::getMethodStr() const {
		string methodStr;
		switch (m_method) {
			case METHOD_POST:
				methodStr = "POST";
				break;
			case METHOD_GET:
			default:
				methodStr = "GET";
				break;
		}
		return methodStr;
	}

	int Http::createRequest(std::string &request) {
		request.clear();
		requese.append(getMethodStr()).append(" ");
		request.append(m_url.getPath()).append(" HTTP/1.1\r\n");
		request.append("Host: ").append(m_url.getHostname()).append("\r\n");
		request.append("\r\n");
		return 0;
	}

	int Http::sendRequest(Socket sock, const string &request) {
		sock.send(request.c_str(), request.size());
	}

	int Http::recvResponse(Socket sock, string &response) {
		char buf[1024*10];
		int len = sock.recv(buf, 1024*10);
		buf[len] = '\0';
		printf("%s", buf);
	}

	int Http::getResponse(string &response) {
		// create http request
		string request;
		int res = 0; // result
		Socket sock(m_url.getHostname(), m_url.getPort());
		res = sock.setupSocket();
		res = createRequest(request);
		res = sendRequest(sock, request);
		return recvRespone(sock, response);
	}

	// void test();
}

		
		
