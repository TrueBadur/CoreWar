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
    #TODO ./run_speed.sh -c ../data/corewar -t 0.001 -i ./outfiles/0.wave.not.txt -o wave
    #TODO ./run_speed.sh -c ../data/corewar -t 0 -i ./outfiles/5.wave.not.txt -o wave
    exit 1
}

while getopts 'i:o:c:t:' opts; do
  case "${opts}" in
    i) inputfile=${OPTARG} ;;
    o) outputfile=${OPTARG}  ;;
    c) CMD_core=${OPTARG} ;;
    t) timeout=${OPTARG}  ;;
    *) print_usage ;;
  esac
done

#check of init vals
if [ -z "${inputfile}" ] || [ -z "${outputfile}" ] || [ -z "${CMD_core}" ] || [ -z "${timeout}" ]; then
    print_usage
fi

#script

TMP=$(dirname $outputfile)/tmp.txt
OUT=$outputfile.txt
OUTNON=$outputfile.not.txt

rm    $OUT $OUTNON $TMP
touch $OUT $OUTNON $TMP

game() {
    FULL_CMD="$CMD_core $CMD"
    #echo $FULL_CMD
    rm $TMP
    ($FULL_CMD -v 2 | tail -3) > $TMP 2>&1 &
    PID=$!
    if [[ $timeout != 0 ]]; then
      (sleep $timeout ; pkill -P $PID &> /dev/null) &
    else
      echo "No timeout: $FULL_CMD"
    fi
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
        echo "⛔️ (> $timeout) $FULL_CMD"
        echo $CMD >> $OUTNON
    fi
}

num=0
total=$(cat $inputfile | wc -l | xargs)

echo $total
cat $inputfile | while read line
do
    CMD=$line
    game
done
echo ok
exit 1