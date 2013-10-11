/*************************************************************************
    > File Name: lyxCookieStorage.h
    > Author: liyuxing
    > Mail: liyustar@gmail.com 
    > Created Time: 2013年10月11日 星期五 20时48分49秒
 ************************************************************************/

#ifndef LYXCOOKIESTORAGE_H
#define LYXCOOKIESTORAGE_H

#include "lyxCookie.h"
#include "lyxUrl.h"
#include <map>
#include <set>

namespace lyx {

	typedef class CookieStorage * CookieStorageInstence;

	class CookieStorage {
		private:
			static CookieStorageInstence m_cookiestorage;
			std::map<Url, std::set<Cookie> > m_cookieSet;
			CookieStorage() { }

		public:
			static CookieStorageInstence getCookieStorageInstence();
			int addCookie(Url url, Cookie cookie);

	};
}

#endif // LYXCOOKIESTORAGE_H
