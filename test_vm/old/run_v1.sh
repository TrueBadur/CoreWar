#!/bin/sh

# trap ctrl-c and call ctrl_c()
trap ctrl_c INT

function ctrl_c() {
        echo "** Trapped CTRL-C"
}

function game() {
    FULL_CMD=$CMD_core$CMD

    (\time $FULL_CMD -d $LIM -v 2 | tail -3) > outfile 2>&1

    string=$(head -2 outfile | tail -1)
    if [[ $string == *"0x0f40"* ]]; then
        echo "⛔️  $FULL_CMD"
        echo $CMD >> $LIM.not.txt
    else
        echo "✅  $FULL_CMD"
        echo "$(cat outfile | tail -3 | head -1 | sed 's/It is now cycle //') $CMD" >> $LIM.txt
    fi
}

#inputfile=champ_vs_champ
#LIM=10000
inputfile=champ_vs_champ
LIM=999999999
CMD_core="../data/corewar "

rm    $LIM.txt $LIM.not.txt
touch $LIM.txt $LIM.not.txt

cat $inputfile | while read line
do
    CMD=$line
    game
done

exit 1