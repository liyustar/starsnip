/*************************************************************************
    > File Name: lyxCookie.cpp
    > Author: liyuxing
    > Mail: liyustar@gmail.com 
    > Created Time: 2013年10月11日 星期五 13时28分20秒
 ************************************************************************/

#include "lyxCookie.h"
#include "lyxUrl.h"
#include <iostream>
using namespace std;

namespace lyx {

//	Cookie::Cookie()
//		: m_key(""), m_val(""), m_path("/") { }

	Cookie::Cookie(string name, string val, string domain,
			string path, int secure)
		: m_name(name), m_val(val), m_domain(domain),
		m_path(path), m_secure(secure) { }

	// Cookie::Cookie(const Cookie& cookieObj);
	Cookie::~Cookie() { }

	// Cookie(const Cookie&);

	void Cookie::print() {
		cout << "name: " << m_name << "\tval: " << m_val << endl;
	}

	// getter
	string Cookie::getCookieStr() const {
		string cookieStr;
		cookieStr.append(m_name).append("=").append(m_val);
		return cookieStr;
	}
	string Cookie::getPath() const {
		return m_path;
	}

	Cookie Cookie::parseSetCookieString(Url url, const string &setCookieStr) {
		string name, val, domain, path;
		int pos = 0, end = 0, secure = 0;
		pos = setCookieStr.find_first_not_of(" ");
		end = setCookieStr.find("=", pos);
		name = setCookieStr.substr(pos, end - pos);
		pos = end + 1;
		end = setCookieStr.find_first_of(" ;", pos);
		val = setCookieStr.substr(pos, end - pos);

		pos = setCookieStr.find("path=");
		if (string::npos != pos) {
			pos += 5;
			end = setCookieStr.find_first_of(" ;", pos);
			path = setCookieStr.substr(pos, end - pos);
		}

		pos = setCookieStr.find("domain=");
		if (string::npos != pos) {
			pos += 7;
			end = setCookieStr.find_first_of(" ;", pos);
			path = setCookieStr.substr(pos, end - pos);
		}

		pos = setCookieStr.find(" secure;");
		if (string::npos != pos) {
			secure = 1;
		}

		return Cookie(name, val, domain, path, secure);
	}

	void Cookie::test() { }
}
