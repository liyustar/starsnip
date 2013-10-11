/*************************************************************************
    > File Name: lyxCookie.h
    > Author: liyuxing
    > Mail: liyustar@gmail.com 
    > Created Time: 2013年10月11日 星期五 13时29分25秒
 ************************************************************************/

#ifndef LYXCOOKIE_H
#define LYXCOOKIE_H

#include <string>

namespace lyx {

	class Cookie {
		private:
		Cookie();
		std::string m_key;
		std::string m_val;
		std::string m_path;

		// Cookie(const Cookie&);
		void print();

		public:
		Cookie(std::string key, std::string val);
		// Cookie(const Cookie& cookieObj);
		~Cookie();

		// getter
		std::string getCookieStr() const;
		std::string getPath() const;

		void test();
	};
}

#endif // LYXCOOKIE_H
