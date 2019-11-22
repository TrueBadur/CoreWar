#!/bin/sh

function compare() {

    if [[ $TO_RUN == f* ]]; then
      echo "📢  $TO_RUN"
      echo $TO_RUN >> $skipfile
      return 1;
    fi

    eval $MAIN_CORE$TO_RUN > dump_main.txt
    eval $TEST_CORE$TO_RUN > dump_test.txt
    diff dump_main.txt dump_test.txt > outdiff.txt
    if [ -s outdiff.txt ]
    then
      echo "🚨  $TO_RUN"
      echo $TO_RUN >> $outfile
      echo "$MAIN_CORE$TO_RUN > dump_main.txt" >> $outfile
      echo "$TEST_CORE$TO_RUN > dump_test.txt" >> $outfile
      echo "diff dump_main.txt dump_test.txt > outdiff.txt" >> $outfile
      echo "" >> $outfile
    else
      echo "👍  $TO_RUN"
    fi
}

inputfile="rerun.txt"
outfile=result_$inputfile
skipfile=skip_$inputfile
MAIN_CORE="../data/corewar -d "
TEST_CORE="../corewar -dump "

rm    $outfile $skipfile
touch $outfile $skipfile

cat $inputfile | while read line
do
    TO_RUN=$line
    compare
done

exit 1