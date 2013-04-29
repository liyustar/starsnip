#ifndef _FILEUTIL_H
#define _FILEUTIL_H

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
