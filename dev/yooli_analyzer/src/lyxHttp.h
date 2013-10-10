#ifndef LYXHTTP_H
#define LYXHTTP_H

#include "lyxUrl.h"
#include "lyxSocket.h"
#include <string>
#include <map>

namespace lyx {

	typedef enum {
		METHOD_UNKNOW,
		METHOD_GET,
		METHOD_POST,
	}METHOD_TYPE;

	class Http {
		private:
		Url m_url;
		METHOD_TYPE m_method;
		std::map<std::string, std::string> m_params;

		// Http(const Http&);
		void print();

		std::string getMethodStr() const;
		std::string getParamsStr() const;
		int createRequest(std::string &request);
		int sendRequest(Socket *psock, const std::string &request);
		int recvResponse(Socket *psock, std::string &response);

		public:
		Http();
		Http(Url url);
		// Http(const Http& httpObj);
		~Http();
		int setMethod(std::string method);
		int addParam(const std::string key, const std::string val);

		// return status
		int getResponse(std::string &response);

		void test();
	};
}

#endif // LYXHTTP_H
