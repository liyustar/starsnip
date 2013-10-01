#include "lyxUrl.h"
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

		Http();
		Http(const Http&);
		void print();

		int createRequest(std::string &request);
		int sendRequest(const std::string &request) const;
		int recvResponse(std::response);

		public:
		Http(Url url);
		// Http(const Http& httpObj);
		~Http();
		int setMethod(std::string method);

		// return status
		int getResponse(std::string &response);

		void test();
	};
}

		
		
