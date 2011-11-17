#!/bin/bash

# Script to convert basic transition counts into 4ti2 input.
# Assumes S=3

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
    echo "6 $mylc" > 3_${i}_gentrans_noloops_trans_noinit.mat
    gzip -d < 3_${i}_gentrans_noloops_trans_noinit.txt.gz | ./transpose.sh >> 3_${i}_gentrans_noloops_trans_noinit.mat
done
