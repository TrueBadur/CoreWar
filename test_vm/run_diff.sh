#!/bin/sh


inputfile=''
outfile=''
MAIN_CORE='../data/corewar'
MAIN_DUMP_FLAG=" -d "
TEST_CORE="../corewar"
TEST_DUMP_FLAG=" -dump "


print_usage() {
  printf "Usage:\n"
  exit 1
}

# ./run_diff.sh -i ./dir_fast_war/fast_war.txt -o out -c ../data/corewar -t ../corewar
# ./run_diff.sh -i ./dir_mid_war/mid_war.txt -o out -c ../data/corewar -t ../corewar
#TODO ./run_diff.sh -c ../data/corewar -t ../corewar -i ./outfiles/1.wave.txt -o ./outfiles/Errors


while getopts 'i:o:c:t:' opts; do
  case "${opts}" in
    i) inputfile=${OPTARG} ;;
    o) outfile=${OPTARG} ;;
    c) MAIN_CORE=${OPTARG}$MAIN_DUMP_FLAG ;;
    t) TEST_CORE=${OPTARG}$TEST_DUMP_FLAG ;;
    *) print_usage ;;
  esac
done
#check of init vals
if [ -z "${inputfile}" ] || [ -z "${outfile}" ] || [ -z "${MAIN_CORE}" ] || [ -z "${TEST_CORE}" ]; then
    print_usage
fi


function compare() {

    eval $MAIN_CORE$TO_RUN > $dump_main
    eval $TEST_CORE$TO_RUN > $dump_test
    #echo "diff $dump_main $dump_test > $outdiff"
    diff $dump_main $dump_test > $outdiff
    num=$[ $num + 1]
    echo "$num \t/ $total"
    if [ -s $outdiff ]; then
      echo "🚨  $TO_RUN"
      echo $TO_RUN >> $outfile
      echo $TO_RUN >> $fullout
      echo "$MAIN_CORE$TO_RUN > $dump_main" >> $fullout
      echo "$TEST_CORE$TO_RUN > $dump_test" >> $fullout
      cat $dump_test >> $fullout
      echo "diff $dump_main $dump_test > $outdiff" >> $fullout
      echo "" >> $fullout
    else
      echo "👍  $TO_RUN"
    fi
}

dump_main=$(dirname $outfile)/dump_main.txt
dump_test=$(dirname $outfile)/dump_test.txt
outdiff=$(dirname $outfile)/diff.txt

fullout="$outfile.full.txt"
outfile="$outfile.txt"

num=0
total=$(cat $inputfile | wc -l | xargs)

cat $inputfile | while read line
do
    TO_RUN=$line
    compare
done

exit 1