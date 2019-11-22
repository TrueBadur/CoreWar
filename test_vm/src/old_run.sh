#!/bin/sh

LIM=10000

touch $LIM.txt
touch $LIM.not.txt

function game() {
    (\time $CMD -d $LIM -v 2 | tail -3) > outfile 2>&1

    string=$(head -2 outfile | tail -1)
    if [[ $string == *"0x0f40"* ]]; then
        echo "Not done!"
        echo $CMD >> $LIM.not.txt
    else
        echo "Good"
        echo "" >> $LIM.txt
        echo $CMD >> $LIM.txt
        cat outfile >> $LIM.txt
    fi
}

arr=(../data/compiled/*)

# iterate through array using a counter
for ((i=0; i<${#arr[@]}; i++)); do
    #do something to each element of array
    #echo "${arr[$i]}"
    for ((j=i; j<${#arr[@]}; j++)); do
        #do something to each element of array
        #echo -e "\t${arr[$j]}"
        CMD="../data/corewar ${arr[$i]} ${arr[$j]}"
        echo $CMD
        echo -e "\t$i vs $j"
        game
    done
done

exit 1