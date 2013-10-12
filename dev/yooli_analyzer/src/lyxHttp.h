#ifndef LYXHTTP_H
#define LYXHTTP_H

#include "lyxUrl.h"
#include "lyxSocket.h"
#include <string>
#include <map>

namespace lyx {

	class Http {

		public:
			typedef enum {
				METHOD_UNKNOW,
				METHOD_GET,
				METHOD_POST,
			}METHOD_TYPE;

			typedef enum {
				TOKEN_UNKNOW,
				TOKEN_CONTENT_LENGTH,
				TOKEN_SET_COOKIE,
			}TOKEN_TYPE;

			typedef void (*TOKEN_METHOD)(std::string);

			typedef struct {
				TOKEN_TYPE tok;
				std::string tokStr;
				TOKEN_METHOD tokMethod;
			}HeadProcess;

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
			int recvResponse(Socket *psock, std::string &header, std::string &response);
			int analyzeResponseHeader(const std::string &header, int &status);
			int processHeaderLine(const std::string &token, const std::string &content);
			int analyseHeaderFirstLine(const std::string &firstLine);
			int analyseHeaderLine(const std::string &line);

	};
}

#endif // LYXHTTP_H
