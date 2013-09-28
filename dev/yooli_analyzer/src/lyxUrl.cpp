#include "lyxUrl.h"
#include <string>
#include <cstring> // for strlen
#include <cstdlib> // for atoi
#include <iostream>

using namespace std;

namespace lyx {

	Url::Url(string urlStr) {
		m_url = urlStr;
		urlAnalyse(m_url);
	}

//	Url::Url(const Url& urlObj) {
//		*this = urlObj;
//	}

	Url::~Url() {
	}

	string Url::getUrlStr() {
		return m_url;
	}

	/**
	 * parse url
	 * success: 0 		fail: 1
	 */
	int Url::urlAnalyse(string urlStr) {
		int pos = 0, markpos = 0;
		int parsedone = 0;

		// get protocol
		pos = urlStr.find("://", pos);
		if (string::npos == pos) {
			m_proto = PROTO_UNKNOW;
		} else {
			string protoStr = urlStr.substr(markpos, pos);
			if (protoStr.compare("http") == 0) {
				m_proto = PROTO_HTTP;
			} else if (protoStr.compare("https") == 0) {
				m_proto = PROTO_HTTPS;
			} else {
				m_proto = PROTO_UNKNOW;
			}
			pos += strlen("://");
		}

		// get host
		markpos = pos;
		pos = urlStr.find_first_of("/", markpos);
		string host;
		if (string::npos == pos) {
			host = urlStr.substr(markpos);
			parsedone = 1;
		} else {
			host = urlStr.substr(markpos, pos - markpos);
		}

		// parse host
		string portStr;
		pos = host.find_first_of(":");
		if (string::npos == pos) {
			m_hostname = host;
			m_port = PORT_UNKNOW;
		} else {
			m_hostname = host.substr(0, pos);
			portStr = host.substr(pos + 1);
			m_port = atoi(portStr.c_str());
		}
		if (parsedone == 1) {
			return 0;
		}
	}

	void Url::print() {
		cout << "UrlOBj:" << endl;
		cout << m_url << endl;
		cout << m_proto << endl;
		cout << m_hostname << endl;
		cout << m_port << endl;
		cout << endl;
	}

	void Url::test() {
		print();
	}

}

