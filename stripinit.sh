#!/bin/bash

# Strips the first $1 fields from every line

# E.g.
# echo 1 2 3 4 5 6 7 8 9 10 | ./stripinit.sh 3 
# Outputs: 4 5 6 7 8 9 10

if [[ $# -ne 1 ]]
then
    echo "Usage:"
    echo "./stripinit.sh <number of fields to strip>"
    echo ""
    echo "Reads from standard input."
    exit 0
fi

awk '{ for (i='$1'+1;i<=NF;i++) { printf("%s ",$i); } printf("\n");}'
