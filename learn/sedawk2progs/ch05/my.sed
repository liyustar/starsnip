s/^\.Se\ "\(.*\)"/\
\1\
/
#s/\.Ah\ "\(.*\)"/\tA. \1/

/^\.Ah/{
s/\.Ah */\
\
@A HEAD = /
s/"//g
s/$/\
/
}

s/^\.Bh\ "\(.*\)"/\t\tB. \1/
/---/!s/--/hello/g

s/\(.*\):\(.*\)/\2:\1/

1i\
.so macros\
.ds CH First Draft

$a\
\
End of file

/-----/a\
haha

# s/^\.sp.*/.sp .5/
/^\.sp/c\
.sp .5
