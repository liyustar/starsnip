#!/bin/sh
#PATTERN="\(^\| \)[\"[{\(]*book[]}\)\"\?\!.,;:\'s]*\( \|$\)"
PATTERN=""
#./gres "\(^\\\| \)book" "OO"  bookwords
grep --color "\(^\| \)[\"[{(]*book[]})\"?\!.,;:'s]*\( \|$\)" bookwords
#grep --color ${PATTERN} bookwords
# ./gres ${PATTERN} "OO"  bookwords
