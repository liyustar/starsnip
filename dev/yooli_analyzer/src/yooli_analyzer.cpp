#include <iostream>
#include <string>
#include "lyxUrl.h"
#include "lyxHttp.h"
using namespace std;

void addCommonHeader(lyx::Http &http) {
	http.addHeader("Accept", "text/plain, */*; q=0.01");
	http.addHeader("User-Agent", "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.69 Safari/537.36");
	http.addHeader("Content-Type", "application/x-www-form-urlencoded; charset=UTF-8");
	http.addHeader("Accept-Encoding", "gzip,deflate,sdch");
	http.addHeader("Accept-Language", "zh-CN,zh;q=0.8");
}

int main() {
	// string yooliUrl = "yttp://www.yooli.com";
	// lyx::Url yooliUrl("https://github.com:443/");
	// lyx::Url yooliUrl("http://www.baidu.com:80/");
	lyx::Url yooliUrl("https://www.yooli.com:443/secure/login.jsp");
	lyx::Http::initHttpAlgorithms();
	lyx::Http yooliHttp(yooliUrl);
	yooliHttp.setMethod("GET");
	addCommonHeader(yooliHttp);


	string response;
	yooliHttp.getResponse(response);
	// cout << " ******************* \n RESPONSE \n *******************" << endl;
	// cout << response;
	// string response = yooliHttp.getResponse();
	// cout << response;

	lyx::Url loginUrl("https://www.yooli.com:443/secure/login.action");
	lyx::Http loginHttp(loginUrl);
	loginHttp.setMethod("POST");
	loginHttp.addParam("nickname", "XXX");
	loginHttp.addParam("password", "XXX");
	loginHttp.addParam("verifycode", "");
	loginHttp.addParam("chkboxautologin", "false");
	loginHttp.addHeader("Referer", "https://www.yooli.com/secure/login.jsp");
	addCommonHeader(loginHttp);
	
	response.clear();
	loginHttp.getResponse(response);

	lyx::Url yooliUrl2("http://www.yooli.com:80");
	lyx::Http login2Http(yooliUrl2);
	login2Http.setMethod("GET");
	addCommonHeader(login2Http);

	response.clear();
	login2Http.getResponse(response);
	cout << response;

	return 0;
}

