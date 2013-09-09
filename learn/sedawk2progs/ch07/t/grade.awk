{
one_tol = 0
one_tol = $2 + $3 + $4 + $5 + $6

avg = one_tol / 5
print $1, avg
tol += one_tol
}
END {
print tol
print NF
print NR
}
