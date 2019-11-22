#!/bin/sh

# trap ctrl-c and call ctrl_c()
trap ctrl_c INT

function ctrl_c() {
    echo "** Trapped CTRL-C"
}

function game() {
    FULL_CMD=$CMD_core$CMD

    echo $FULL_CMD
    ($FULL_CMD -v 2 | tail -3) > outfile 2>&1

    string=$(tail -1 outfile)
    if [[ $string == *"Contestant"* ]]; then
        echo "✅  $FULL_CMD"
        value=$(tail -2 outfile | head -1)
        if [[ $value != *"It is now cycle "* ]]; then
            value=$(tail -3 outfile | head -1)
        fi
        echo "$(echo $value | sed 's/It is now cycle //' | sed 's/$/ - 1/' | bc) $CMD" >> $LIM.txt
    else
        echo "⛔️  $FULL_CMD"
        echo $CMD >> $LIM.not.txt
    fi
}

#inputfile=champ_vs_champ
#LIM=10000
inputfile=time.not.txt
LIM=time_long
CMD_core="../data/corewar "

rm    $LIM.txt $LIM.not.txt
touch $LIM.txt $LIM.not.txt

cat $inputfile | while read line
do
    CMD=$line
    game
done

exit 1