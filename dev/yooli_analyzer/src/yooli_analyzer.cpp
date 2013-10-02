#include <iostream>
#include <string>
#include "lyxUrl.h"
#include "lyxHttp.h"
using namespace std;

int main() {
	// string yooliUrl = "yttp://www.yooli.com";
	lyx::Url yooliUrl("http://www.yooli.com:80/");
	lyx::Http yooliHttp(yooliUrl);
	yooliHttp.setMethod("GET");
//	yooliHttp.setTimeout(8000);
//	yooliHttp.setUserAgent("");
//	yooliHttp.setAccept("");

	string response;
	yooliHttp.getResponse(response);
	cout << " ******************* \n RESPONSE \n *******************" << endl;
	cout << response;
	// string response = yooliHttp.getResponse();
	// cout << response;
	return 0;
}

