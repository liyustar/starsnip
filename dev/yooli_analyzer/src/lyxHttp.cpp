#include "lyxHttp.h"
#include "lyxUrl.h"
#include "lyxSocket.h"
#include "lyxSslSocket.h"
#include "lyxCookieStorage.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <cstdio>

using namespace std;

static string myitoa(int n) {
	const int INTBUFSIZE = 12;
	char buf[INTBUFSIZE] = {0};
	sprintf(buf, "%d", n);
	string num = buf;
	return num;
}

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

	int Http::addParam(const string key, const string val) {
		// TODO: process '&' '?' etc.
		m_params.insert(make_pair(key, val));
	}

	string Http::getMethodStr() const {
		string methodStr;
		switch (m_method) {
			case METHOD_POST:
				methodStr = "POST";
				break;
			case METHOD_GET: /* no break */
			default:
				methodStr = "GET";
				break;
		}
		return methodStr;
	}

	string Http::getParamsStr() const {
		string paramsStr;
		map<string, string>::const_iterator iter = m_params.begin();
		if (iter != m_params.end()) {
			paramsStr.append(iter->first)
				.append("=").append(iter->second);
			iter++;
		}
		while (iter != m_params.end()) {
			paramsStr.append("&").append(iter->first)
				.append("=").append(iter->second);
			iter++;
		}
		return paramsStr;
	}

	int Http::createRequest(std::string &request) {
		string body, path;
		if (m_method == METHOD_GET) {
			path = m_url.getPath().append("?")
						.append(getParamsStr());
		}
		else {
			path = m_url.getPath();
			body = getParamsStr();
		}
		request.clear();
		request.append(getMethodStr()).append(" ");
		request.append(path).append(" HTTP/1.1\r\n");
		request.append("Host: ").append(m_url.getHostname()).append("\r\n");

		if (!body.empty()) {
			request.append("Content-Length: ")
				.append(myitoa(body.size())).append("\r\n");
		}
		// request.append("Accept: text/html,application/xml,application/xhtml+xml,text/html;*/*\r\n");
		// request.append("User-Agent: LYX PROG/1.0\r\n");
		// request.append("Accept-Charset: IOS-8859-1\r\n");
		// request.append("Accept-Language: en;q=0.5\r\n");
		// request.append("Accept-Encoding: gzip\r\n");
		request.append("Connection: Close\r\n");	// not support keep-alive
		request.append("\r\n");
		if (!body.empty()) {
			request.append(body);
		}
		return 0;
	}

	int Http::sendRequest(Socket *psock, const string &request) {
		psock->send(request.c_str(), request.size());
	}

	int Http::recvResponse(Socket *psock, string &header, string &response) {
		int isFindHeader = false;
		const int BUFLEN = 1024 * 8;
		char buf[BUFLEN + 1];
		int totalrecv = 0;
		do {
			int len = psock->rawRecv(buf, BUFLEN);
			if (len > 0) {
				buf[len] = '\0';
				response += buf;
				// find header
				if (isFindHeader == false
					&& response.find("\r\n\r\n") != string::npos) {
					isFindHeader = true;
					int pos = response.find("\r\n\r\n");
					header = response.substr(0, pos + 4);
					response = response.substr(pos + 4);
					cout << header;
				}
			} else if (len == 0) {
				break;
			} else {
				perror("");
				break;
			}
			totalrecv += len;
		} while(true);
		cout << "recv len: " << totalrecv << endl;
	}

	int Http::analyzeResponseHeader(const string &header, int &status) {
		// TODO: add Cookie to CookieStorage;
		CookieStorageInstence csInstence = CookieStorage::getCookieStorageInstence();
	}

	int Http::getResponse(string &response) {
		// create http request
		string request;
		string header;
		int status = 0;
		int res = 0; // result
		if (443 == m_url.getPort()) {
			SslSocket sock(m_url.getHostname(), m_url.getPort());
			res = sock.setupSocket();
			res = createRequest(request);
			res = sendRequest(&sock, request);
			res = recvResponse(&sock, header, response);
			res = analyzeResponseHeader(header, status);
			return res;
		} else {
			Socket sock(m_url.getHostname(), m_url.getPort());
			res = sock.setupSocket();
			res = createRequest(request);
			res = sendRequest(&sock, request);
			res = recvResponse(&sock, header, response);
			res = analyzeResponseHeader(header, status);
			return res;
		}
	}

	// void test();
}

