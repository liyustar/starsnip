#include "fileutil.h"

File::File(std::string filename) : fname(filename)
{
	if(-1 == stat(fname.c_str(), &fstat))
	{
		err_quit("no file");
	}
}

std::string File::fileMode()
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

