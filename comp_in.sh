#!/bin/bash

maxT=10

if [[ $# -ge 1 ]]
then
    maxT=$1
fi

for i in $(seq 1 $maxT)
do 
    echo $i
    gzip -d < 3_${i}_gentrans_noloops_trans_init.txt.gz | ./stripinit.sh 3 | sort -u | gzip > 3_${i}_gentrans_noloops_trans_noinit.txt.gz
done

for i in $(seq 1 $maxT)
do 
    echo $i
    mylc=`gzip -d < 3_${i}_gentrans_noloops_trans_noinit.txt.gz | wc -l | awk '{print $1}'`
    echo "$mylc 6" > 3_${i}_gentrans_noloops_trans_noinit.in
    gzip -d < 3_${i}_gentrans_noloops_trans_noinit.txt.gz >> 3_${i}_gentrans_noloops_trans_noinit.in
    echo "1" >> 3_${i}_gentrans_noloops_trans_noinit.in
done
