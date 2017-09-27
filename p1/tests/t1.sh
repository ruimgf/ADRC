#!/bin/bash
# Atençao o script tem de ser lançado a partir da pasta p1 !!

set -e
if [ "$#" -ne 1 ]; then
    echo "Usage: t1.sh fileTree"
fi

./main.o $1 > tempfile.tree

DIFF=$(diff <(sort $1) <(sort tempfile.tree))
if [ "$DIFF" == "" ]
then
    echo "Sucess"
else
    echo "error"
fi
rm tempfile.tree
