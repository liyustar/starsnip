/*************************************************************************
    > File Name: lyxCookie.cpp
    > Author: liyuxing
    > Mail: liyustar@gmail.com 
    > Created Time: 2013年10月11日 星期五 13时28分20秒
 ************************************************************************/

#include "lyxCookie.h"
#include <iostream>
using namespace std;

namespace lyx {

	Cookie::Cookie()
		: m_key(""), m_val(""), m_path("/") { }

	Cookie::Cookie(string key, string val)
		: m_key(key), m_val(val), m_path("/") { }

	// Cookie::Cookie(const Cookie& cookieObj);
	Cookie::~Cookie() { }

	// Cookie(const Cookie&);

	void Cookie::print() {
		cout << "key: " << m_key << "\tval: " << m_val << endl;
	}

	// getter
	string Cookie::getCookieStr() const {
		string cookieStr;
		cookieStr.append(m_key).append("=").append(m_val);
		return cookieStr;
	}
	string Cookie::getPath() const {
		return m_path;
	}

	void Cookie::test() { }
}
