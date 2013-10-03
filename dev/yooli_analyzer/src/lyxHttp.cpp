#include "lyxHttp.h"
#include "lyxUrl.h"
#include "lyxSocket.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

namespace lyx {

	Http::Http() : m_url("") { }

	Http::Http(Url url) : m_url(url) { }

	// void print();

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
		request.append(getMethodStr()).append(" ");
		request.append(m_url.getPath()).append(" HTTP/1.1\r\n");
		request.append("Host: ").append(m_url.getHostname()).append("\r\n");
		// request.append("Accept: text/html,application/xml,application/xhtml+xml,text/html;*/*\r\n");
		// request.append("User-Agent: LYX PROG/1.0\r\n");
		// request.append("Accept-Charset: IOS-8859-1\r\n");
		// request.append("Accept-Language: en;q=0.5\r\n");
		// request.append("Accept-Encoding: gzip\r\n");
		// request.append("Connection: Keep-Alive\r\n");
		request.append("\r\n");
		return 0;
	}

	int Http::sendRequest(Socket sock, const string &request) {
		sock.send(request.c_str(), request.size());
	}

	int Http::recvResponse(Socket sock, string &response) {
		const int buflen = 200;
		char buf[buflen];
		int len = sock.recv(buf, buflen);
		if (len != -1) {
			buf[len] = '\0';
			response = buf;
		} else {
			perror("");
		}
		cout << "recv len: " << len << endl;
	}

	int Http::getResponse(string &response) {
		// create http request
		string request;
		int res = 0; // result
		Socket sock(m_url.getHostname(), m_url.getPort());
		res = sock.setupSocket();
		res = createRequest(request);
		res = sendRequest(sock, request);
		return recvResponse(sock, response);
	}

	// void test();
}

