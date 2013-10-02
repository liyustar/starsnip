#include <string>

namespace lyx {

	class Socket {
		private:
		std::string m_host;
		int m_port;
		int m_sock;

		Socket();
		Socket(const Socket&);
		void print();

		public:
		Socket(const std::string &h, int p);
		// Socket(const Socket& sockObj);
		~Socket();
		int setupSocket();

		void test();
	};
}

		
		
