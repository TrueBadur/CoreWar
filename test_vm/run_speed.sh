#!/bin/sh

# trap ctrl-c and call ctrl_c()

#trap ctrl_c INT
#
#ctrl_c() {
#    echo "** Trapped CTRL-C"
#}

inputfile=''
outputfile=''
CMD_core="../data/corewar "

print_usage() {
    printf "\nUsage:\tall options are required\n"
    printf "\t-i \t: input file with champs\n"
    printf "\t-o \t: output file with result and '.not' bad cases\n"
    printf "Like next one 👇:\n"
    printf "./run_speed.sh -i champ_vs_champ -o fast_war\n\n"
    printf "or \t      👇:\n"
    printf "./run_speed.sh -i dir_fast_war/fast_war.not.txt -o mid_war\n\n"
    exit 1
}

while getopts 'i:o:' opts; do
  case "${opts}" in
    i) inputfile=${OPTARG} ;;
    o) outputfile=${OPTARG}  ;;
    *) print_usage ;;
  esac
done

#check of init vals
if [ -z "${inputfile}" ] || [ -z "${outputfile}" ] ; then
    print_usage
fi

#script
DIR=dir_$outputfile
rm -r $DIR
mkdir $DIR

TMP=./$DIR/tmp.txt
OUT=./$DIR/$outputfile.txt
OUTNON=./$DIR/$outputfile.not.txt

rm    $OUT $OUTNON $TMP
touch $OUT $OUTNON $TMP

game() {
    FULL_CMD=$CMD_core$CMD

    echo $FULL_CMD
    ($FULL_CMD -v 2 | tail -3) > $TMP 2>&1

    string=$(tail -1 $TMP)
    if [[ $string == *"Contestant"* ]]; then
        echo "✅  $FULL_CMD"
        value=$(tail -2 $TMP | head -1)
        if [[ $value != *"It is now cycle "* ]]; then
            value=$(tail -3 $TMP | head -1)
        fi
        echo "$(echo $value | sed 's/It is now cycle //'\
              | sed 's/$/ - 1/' | bc) $CMD" >> $OUT
    else
        echo "⛔️  $FULL_CMD"
        echo $CMD >> $OUTNON
    fi
}

cat $inputfile | while read line
do
    CMD=$line
    game
done
exit 1