#ifndef LYXHTTP_H
#define LYXHTTP_H

#include "lyxUrl.h"
#include "lyxSocket.h"
#include <string>

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

		// Http(const Http&);
		void print();

		std::string getMethodStr() const;
		int createRequest(std::string &request);
		int sendRequest(Socket sock, const std::string &request);
		int recvResponse(Socket sock, std::string &response);

		public:
		Http();
		Http(Url url);
		// Http(const Http& httpObj);
		~Http();
		int setMethod(std::string method);

		// return status
		int getResponse(std::string &response);

		void test();
	};
}

#endif // LYXHTTP_H
