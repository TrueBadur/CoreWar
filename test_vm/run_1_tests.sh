#!/bin/sh

out_dir='./outfiles'
inputfile="./outfiles/test2run"
out_file=$out_dir/test2run

rm ./outfiles/Errors.txt
rm ./outfiles/Errors.full.txt

cat $inputfile | while read line
do
    echo "./run_diff.sh -c ../data/corewar -t ../corewar -i $line -o ./outfiles/Errors"
    ./run_diff.sh -c ../data/corewar -t ../corewar -i $line -o ./outfiles/Errors
done
exit 1