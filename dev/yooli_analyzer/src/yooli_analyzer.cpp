#include <iostream>
#include <string>
#include "lyxUrl.h"
// #include "HttpRequest.h"
using namespace std;

int main() {
	// string yooliUrl = "yttp://www.yooli.com";
	lyx::Url yooliUrl("http://www.yooli.com:888");
	yooliUrl.test();

	//HttpRequest yooliRequest;
	//yooliRequest.setUrl(yooliUrl);
	
	//string response = yooliRequest.sendRequest();

	//cout << response;
	return 0;
}

