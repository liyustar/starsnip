/*************************************************************************
    > File Name: lyxCookieStorage.cpp
    > Author: liyuxing
    > Mail: liyustar@gmail.com 
    > Created Time: 2013年10月11日 星期五 20时49分01秒
 ************************************************************************/

#include "lyxCookieStorage.h"
#include "lyxCookie.h"
#include "lyxUrl.h"
#include <iostream>
#include <map>
#include <set>
using namespace std;

namespace lyx {

//	static CookieStorageInstence CookieStorage::getCookieStorageInstence() {
//		if (m_cookiestorage == NULL) {
//			m_cookiestorage = new CookieStorage();
//		}
//		return m_cookiestorage;
//	}

	int  CookieStorage::addCookie(Url url, Cookie cookie) {
		// TODO: find url in map, add cookie in set;
	}

}
