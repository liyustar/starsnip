#include <iostream>
#include <string>
#include "lyxUrl.h"
#include "HttpRequest.h"
using namespace std;

int main() {
	string yooliUrl = "http://www.yooli.com"

	HttpRequest yooliRequest;
	yooliRequest.setUrl(yooliUrl);
	
	string response = yooliRequest.sendRequest();

	cout << response;
	return 0;
}

