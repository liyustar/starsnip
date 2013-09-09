 ~ jo/ { print bash }
$1 ~ /jo/ { print /bash }
$1 ~ /jo/ { print $0 }
$1 == \ { print $0 }
$1 == "john" { print $0 }
