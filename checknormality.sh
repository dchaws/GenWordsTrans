#!/bin/bash

for i in 3_*_gentrans_noloops_trans_noinit.in
do 
    blarg="${i/\.in/.out}"
    if [[ -e "$blarg" ]]
    then 
        numTrans=`head -n 1 $i | awk '{print $1}'`
        numHB=`head -n 1 ${i/\.in/.out} | awk '{print $1}'`
        echo "$i  $numTrans $numHB"
        if [[ $numTrans -ne $numHB ]]
        then
            echo '    Not normal!'
        fi
    fi
done 
