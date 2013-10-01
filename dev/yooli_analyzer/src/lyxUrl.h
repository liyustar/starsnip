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

		// getter
		std::string getUrlStr() const;
		std::string getHostname() const;
		std::string getPath() const;
		int getPort() const;

		void test();
	};
}

		
		
