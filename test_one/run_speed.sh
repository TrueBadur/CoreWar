#!/bin/sh

# trap ctrl-c and call ctrl_c()

#trap ctrl_c INT
#
#ctrl_c() {
#    echo "** Trapped CTRL-C"
#}

inputfile=''
outputfile=''
CMD_core=''
timeout=1
out_dir=''

print_usage() {
    printf "\nUsage:\tall options are required\n"
    printf "\t-i \t: input file with champs\n"
    printf "\t-o \t: output file with result and '.not' bad cases\n"
    printf "\t-c \t: path to corewar\n"
    printf "\t-t \t: timeout\n\n"
    printf "Like next one 👇:\n"
    printf "./run_speed.sh -c ../data/corewar -t 1 -i champ_vs_champ -o fast_war\n\n"

    printf "or \t      👇:\n"
    printf "./run_speed.sh -c ../data/corewar -t 10 -i dir_fast_war/fast_war.not.txt -o mid_war\n\n"
    #TODO w
    #TODO ./run_init.sh -t ../data/compiled -f 0.non.txt -w outfiles
    #TODO ./run_speed.sh -c ../data/corewar -t 0.1 -i ./outfiles/0_wave.non.txt -o 1_wave -w outfiles
    exit 1
}

while getopts 'i:o:c:t:w:' opts; do
  case "${opts}" in
    i) inputfile=${OPTARG} ;;
    o) outputfile=${OPTARG}  ;;
    c) CMD_core=${OPTARG} ;;
    t) timeout=${OPTARG}  ;;
    w) out_dir=${OPTARG} ;;
    *) print_usage ;;
  esac
done

#check of init vals
if [ -z "${inputfile}" ] || [ -z "${outputfile}" ] || [ -z "${CMD_core}" ] || [ -z "${timeout}" ]; then
    print_usage
fi

#script
out_dir="./$out_dir"

TMP=./$out_dir/tmp.txt
OUT=./$out_dir/$outputfile.txt
OUTNON=./$out_dir/$outputfile.not.txt

rm    $OUT $OUTNON $TMP
touch $OUT $OUTNON $TMP

game() {
    FULL_CMD="$CMD_core $CMD"
    #echo $FULL_CMD
    rm $TMP
    ($FULL_CMD -v 2 | tail -3) > $TMP 2>&1 &
    PID=$!
    (sleep $timeout ; pkill -P $PID &> /dev/null) &
    PID_KILLER=$!

    wait $PID &> /dev/null
    pkill -P $PID_KILLER &> /dev/null
    # for check use:  ps aux | grep 'corewar'

    string=$(tail -1 $TMP)
    num=$[ $num + 1]
    echo "$num \t/ $total"
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

num=0
total=$(cat $inputfile | wc -l | xargs)

cat $inputfile | while read line
do
    CMD=$line
    game
done
exit 1