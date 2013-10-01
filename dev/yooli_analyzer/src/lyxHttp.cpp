#include "lyxHttp.h"
#include "lyxUrl.h"
#include <string>

using namespace std;

namespace lyx {

	Http::Http() {
	}

	Http::Http(const Http& httpObj) {
		*this = httpObj;
	}

	// void print();

	Http::Http(Url url) {
		m_url = url;
	}

	Http::~Http() {}

	int Http::setMethod(string methodStr) {
		if (methodStr.compare("GET") == 0
			|| methodStr.compare("get") == 0) {
			m_method = METHOD_GET;
		} else if (methodStr.compare("POST") == 0
					|| methodStr.compare("post") == 0) {
			m_method = METHOD_POST;
		} else {
			m_method = METHOD_UNKNOW;
		}
	}

	int Http::createRequest(std::string &request) {

	}

	int Http::sendRequest(const std::string &request) {

	}

	int Http::recvResponse(std::response) {

	}

	int Http::getResponse(string &response) {
		// create http request
		string request;
		int res = 0; // result
		res = createRequest(request);
		res = sendRequest(request);
		return recvRespone(response);
	}

	// void test();
}

		
		
