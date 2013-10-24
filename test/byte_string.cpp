/*************************************************************************
    > File Name: byte_string.cpp
    > Author: liyuxing
    > Mail: liyustar@gmail.com 
    > Created Time: 2013年10月25日 星期五 00时19分01秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void print_str_info(const string &str) {
	cout << "str: " << endl;
	for (int i=0; i<str.length(); i++) {
		cout << static_cast<int>(str[i]) << " ";
	}
	cout << endl;
	cout << "length: " << str.length() << endl;
	cout << endl;
}

int main() {
	char cstr[] = { 'a', 'b', 'c', '\0', 'd' };
	string str, append;

	str.assign(cstr, 5);
	print_str_info(str);

	append.assign(&cstr[1], 4);
	print_str_info(append);

	str += append;
	print_str_info(str);

	str.append(&cstr[2], 3);
	print_str_info(str);
}
