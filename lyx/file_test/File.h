#ifndef _FILE_H
#define _FILE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "apue.h"

class File
{
	std::string fname;
	struct stat fstat;
	public:
		File(std::string filename);
		std::string fileMode();
};

#endif // _FILE_H
