#!/bin/bash

# Script that will generate first $1 design matrices with no selfloops

# -Z will zip up the files.
# -U will strip the initial states, sort and uniq the files and zip them. -Z must also be set.


# Default is 10
numMat=10

if [[ $# -ge 1 ]]
then
    numMat=$1
fi

zipFiles=0
sortTrans=0

if [[ $# -ge 2 ]]
then
    if [[ $2 == "-Z" ]]
    then
        zipFiles=1
    fi
fi

if [[ $# -ge 3 ]]
then
    if [[ $3 == "-U" ]]
    then
        sortTrans=1
    fi
fi




filePre="3_"
fileApp="_gentrans_noloops_trans_init.txt"

zipFilesFileApp="_gentrans_noloops_trans_init_strip_sort_uniq"

echo "numMat = $numMat"
echo "zipFiles = $zipFiles"
echo "sortTrans = $sortTrans"
echo "filePre = $filePre"
echo "fileApp = $fileApp"
echo "zipFilesFileApp = $zipFilesFileApp"

if [[ $zipFiles -eq 1 ]]
then

    ./gentrans 3 1 | gzip > ${filePre}1${fileApp}.gz
else
    ./gentrans 3 1 > ${filePre}1${fileApp}
fi

for i in $(seq 2 $numMat)
do 
    echo Computing $i 
    date
    if [[ $zipFiles -eq 1 ]]
    then
        gzip -d < ${filePre}$(( i - 1))${fileApp}.gz | ./gentrans 3 $i -L | gzip > ${filePre}${i}${fileApp}.gz
    else
        time ./gentrans 3 $i -L < ${filePre}$(( i - 1))${fileApp} > ${filePre}${i}${fileApp}
    fi

   
    if [[ $zipFiles -eq 1 && $sortTrans -eq 1 ]]
    then
        echo "Stripping initial states, sort and uniq and gzip data from run $(( i - 1))."
        # Now take previous run, strip out initial states, sort and uniq. Heck, gzip it too
        gzip -d < ${filePre}$(( i - 1))${fileApp}.gz | ./stripinit.sh 3 | sort | uniq | gzip > ${filePre}$(( i - 1))${zipFilesFileApp}.gz
        rm -f ${filePre}$(( i - 1))${fileApp}.gz
    fi

done

i=$(( numMat + 1))
if [[ $zipFiles -eq 1 && $sortTrans -eq 1 ]]
then
    echo "Stripping initial states, sort and uniq and gzip data from run $(( i - 1))."
    # Now take previous run, strip out initial states, sort and uniq. Heck, gzip it too
    gzip -d < ${filePre}$(( i - 1))${fileApp}.gz | ./stripinit.sh 3 | sort | uniq | gzip > ${filePre}$(( i - 1))${zipFilesFileApp}.gz
    rm -f ${filePre}$(( i - 1))${fileApp}.gz
fi
