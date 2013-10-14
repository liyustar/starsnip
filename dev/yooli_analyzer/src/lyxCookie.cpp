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

	void Cookie::test() { }
}
