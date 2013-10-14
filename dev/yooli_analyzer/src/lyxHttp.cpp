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

	map<string, Http::TOKEN_TYPE> Http::headerTokenMap;
	map<Http::TOKEN_TYPE, Http::TOKEN_METHOD> Http::tokenMethodMap;

	static Http::HeaderProcess headerProc[] = {
		{Http::TOKEN_CONTENT_LENGTH,	"Content-Length",	Http::parseContentLength},
		{Http::TOKEN_SET_COOKIE,		"Set-Cookie",		Http::parseSetCookie},
		{Http::TOKEN_UNKNOW, "", NULL }
	};

	Http::Http() : m_url("") { }

	Http::Http(Url url) : m_url(url) { }

	// void print();

	Http::~Http() {}

	int Http::initHttpAlgorithms() {
		static int hasInit = 0;
		if (hasInit == 1) return 0;
		hasInit = 1;
		loadHeaderTokenMap();
		return 0;
	}

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
					// cout << header;
				}
			} else if (len == 0) {
				break;
			} else {
				perror("");
				break;
			}
			totalrecv += len;
		} while(true);
		// cout << "recv len: " << totalrecv << endl;
	}

	int Http::processHeaderLine(const string &tokStr, const string &content) {
		TOKEN_TYPE token;
		TOKEN_METHOD method;
		map<string, TOKEN_TYPE>::iterator tokIter = headerTokenMap.find(tokStr);
		if (tokIter == headerTokenMap.end()) {
			return -1;
		}
		token = tokIter->second;
		map<TOKEN_TYPE, TOKEN_METHOD>::iterator methIter = tokenMethodMap.find(token);
		if (methIter == tokenMethodMap.end()) {
			return -1;
		}
		method = methIter->second;
		return method(this, content);
	}

	int Http::analyseHeaderFirstLine(const string &firstLine) {
		int pos = 0, end = 0, status = 0;
		string token;
		end = firstLine.find_first_not_of(" ", pos);
		token = firstLine.substr(pos, end - pos); // HTTP version
		pos = end + 1;
		end = firstLine.find_first_not_of(" ", pos);
		token = firstLine.substr(pos, end - pos); // response code
		status = atoi(token.c_str());
		pos = end + 1;
		end = firstLine.find_first_not_of("\r\n", pos);
		token = firstLine.substr(pos, end - pos); // response discription
		return status;
	}

	int Http::analyseHeaderLine(const string &line) {
		int pos = 0, end = 0;
		string token, content;
		end = line.find(":");
		if (string::npos == end) {
			return -1;
		}
		token = line.substr(pos, end - pos);
		// skip ' '
		pos = end;
		pos = line.find_first_not_of(" :", pos);
		end = 1 + line.find_last_not_of(" \r\n", line.size());
		content = line.substr(pos, end - pos);
		processHeaderLine(token, content);
	}

	int Http::analyzeResponseHeader(const string &header, int &status) {
		// TODO: add Cookie to CookieStorage;
		CookieStorageInstence csInstence = CookieStorage::getCookieStorageInstence();
		string curLine;
		for (int pos = 0, end = 0;
				end = header.find("\r\n", pos);
				pos = end + 2) {
			curLine = header.substr(pos, end - pos);
			// if (curLine.compare("\r\n") == 0) {
			if (end == pos) {
				break;
			}
			if (pos == 0) {
				// first line
				// eg: HTTP/1.1 200 OK
				status = analyseHeaderFirstLine(curLine);
			}
			else {
				// other line
				// eg: Content-Line: 56\r\n
				analyseHeaderLine(curLine);
			}
		}
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

	// init function
	void Http::loadHeaderTokenMap() {
		for (int i = 0; headerProc[i].tok != TOKEN_UNKNOW; i++) {
			headerTokenMap.insert(make_pair(headerProc[i].tokStr,
											headerProc[i].tok));
			tokenMethodMap.insert(make_pair(headerProc[i].tok,
											headerProc[i].tokMethod));
		}
	}

	// parse header line
	int Http::parseContentLength(HttpCtx ctx, string str) {
		// TODO
		int len = atoi(str.c_str());
		cout << "Content-Length: " << len << endl;
	}

	int Http::parseSetCookie(HttpCtx ctx, string str) {
		// TODO
		cout << "............Set-Cookie: " << str << endl;
	}

	// void test();
}

