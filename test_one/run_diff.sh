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

    eval $MAIN_CORE$TO_RUN > dump_main.txt
    eval $TEST_CORE$TO_RUN > dump_test.txt
    diff dump_main.txt dump_test.txt > outdiff.txt
    num=$[ $num + 1]
    echo "$num \t/ $total"
    if [ -s outdiff.txt ]; then
      echo "🚨  $TO_RUN"
      echo $TO_RUN >> $outfile
      echo $TO_RUN >> $fullout
      echo "$MAIN_CORE$TO_RUN > dump_main.txt" >> $fullout
      echo "$TEST_CORE$TO_RUN > dump_test.txt" >> $fullout
      cat dump_test.txt >> $fullout
      echo "diff dump_main.txt dump_test.txt > outdiff.txt" >> $fullout
      echo "" >> $fullout
    else
      echo "👍  $TO_RUN"
    fi
}

fullout="$outfile.full"

num=0
total=$(cat $inputfile | wc -l | xargs)

cat $inputfile | while read line
do
    TO_RUN=$line
    compare
done

exit 1