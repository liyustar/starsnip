.Rh 0 "DBclose" "closes a database"
.Rh Syntax
.in +5n
.ft B
.nf
.na
void	DBclose(fdesc)
	DBFILE *fdesc;
.in -5n
.ft R
.fi
.ad b
.Rh Usage
.IP "\fIfdesc\fR" 15n
pointer to database file descriptor.
.LP
.Rh Description
DBclose() closes a file when given its database file descriptor.  
Your pending writes to that file will be completed before the
file is closed.  All of your update locks are removed. 
*fdesc becomes invalid.
.LP
Other users are not effected when you call DBclose().  Their update
locks and pending writes are not changed.
.LP
Note that there is no default file as there is in BASIC.  
*fdesc must specify an open file.
.LP
DBclose() is analogous to the CLOSE statement in BASIC.
.LP
.Rh "Return Value"
None.
