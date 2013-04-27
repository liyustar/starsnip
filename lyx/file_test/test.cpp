#include <iostream>
#include "File.h"

int main(int argc, char *argv[])
{
	for(int i=1; i<argc; i++)
	{
		File f(argv[i]);
		std::cout << f.fileMode() << std::endl;
	}
	return 0;
}
