BEGIN {FS = " "; RS = "\n"
OFS = "\n"; ORS = "\n\n" }
{ print $1, $NF}
