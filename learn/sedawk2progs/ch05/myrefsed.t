/^\t/s///
/:\t/s//:/

# s/NAME:\(.*\) - \(.*\)/.Rh 0 "\1" "\2"/
/NAME:/ {
s//.Rh 0 "/
s/ - /" "/
s/$/"/
}

/SYNTAX:/,/^$/ {
/SYNTAX:/c\
.Rh Syntax\
.in +5n\
.ft B\
.nf\
.na
/^$/c\
.in -5n\
.ft B\
.fi\
.ad b
}

/USAGE:/,/^$/ {
/USAGE:/c\
.Rh Usage
/\(.*\)\t- \(.*\)/s//.IP "\\f|\1\\fR" 15n\
\2./
}

/DESC:/,/RETURNS/ {
/DESC:/i\
.LP
s/DESC: *$/.Rh Description/
s/^$/.LP/
}
