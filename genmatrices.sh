#!/bin/bash

# Script that will generate first $1 design matrices with no selfloops

# Default is 10
numMat=10

if [[ $# -ge 1 ]]
then
    numMat=$1
fi

filePre="3_"
fileApp="_gentrans_noloops_trans_init.txt"

./gentrans 3 1 > ${filePre}1${fileApp}

for i in $(seq 2 $numMat)
do 
    echo $i 
    time ./gentrans 3 $i -L < ${filePre}$(( i - 1))${fileApp} > ${filePre}${i}${fileApp}
done
