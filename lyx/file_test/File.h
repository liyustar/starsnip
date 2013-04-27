#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <cstdio>
#include <cstdlib>

class File
{
	std::string fname;
	struct stat fstat;
	public:
		File(std::string filename) : fname(filename)
		{
			if(-1 == stat(fname.c_str(), &fstat))
			{
				perror("no file");
				exit(0);
			}
		}

		std::string fileMode()
		{
			std::string mode;
			if		(S_ISREG(fstat.st_mode)) mode = "regular";
			else if	(S_ISDIR(fstat.st_mode)) mode = "directory";
			else if	(S_ISCHR(fstat.st_mode)) mode = "character special";
			else if	(S_ISBLK(fstat.st_mode)) mode = "block special";
			else if	(S_ISFIFO(fstat.st_mode)) mode = "fifo";
#ifdef	S_ISLNK
			else if	(S_ISLNK(fstat.st_mode)) mode = "symbolic link";
#endif
#ifdef	S_ISSOCK
			else if	(S_ISSOCK(fstat.st_mode)) mode = "socket";
#endif
			else	mode = "** unknown mode **";
			return mode;
		}
};
