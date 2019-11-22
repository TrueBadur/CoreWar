#!/bin/sh

arr=(../data/compiled/*)
out=champ_vs_champ

rm $out
touch $out

# iterate through array using a counter
for ((i=0; i<${#arr[@]}; i++)); do
    #do something to each element of array
    #echo "${arr[$i]}"
    for ((j=i; j<${#arr[@]}; j++)); do
        #do something to each element of array
        #echo -e "\t${arr[$j]}"
        CMD="${arr[$i]} ${arr[$j]}"
        echo $CMD
        echo $CMD >> $out
    done
done

exit 1