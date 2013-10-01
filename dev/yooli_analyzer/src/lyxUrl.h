#include <string>

namespace lyx {

	typedef enum {
		PROTO_UNKNOW,
		PROTO_HTTP,
		PROTO_HTTPS,
	}PROTO_TYPE;

	const int PORT_UNKNOW = -1;

	class Url {
		private:
		std::string m_url;
		PROTO_TYPE m_proto;
		std::string m_hostname;
		std::string m_path;
		int m_port;

		int urlAnalyse(std::string urlStr);
		Url();
		Url(const Url&);
		void print();

		public:
		Url(std::string urlStr);
		// Url(const Url& urlObj);
		~Url();
		std::string getUrlStr();

		void test();
	};
}

		
		
