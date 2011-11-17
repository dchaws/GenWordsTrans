#!/bin/bash

# Utility which tranposes a text file.

awk '
{
for (i=1;i<=NF;i++)
{
 arr[NR,i]=$i;
 if(big <= NF)
  big=NF;
 }
}
 
END {
  for(i=1;i<=big;i++)
   {
    for(j=1;j<=NR;j++)
    {
     printf("%s ",arr[j,i]);
    }
    printf("\n");
   }
}'
