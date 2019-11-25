#!/bin/sh

out_dir="./outfiles"
out_file=$out_dir/test2run

rm -r $out_dir
mkdir $out_dir

idx=0
tm=0.01

./run_init.sh -t ../data/compiled -f $out_dir/$idx.wave.not.txt
idx=$[ $idx + 1]

while [ $tm != 1000.00 ]; do
  echo "./run_speed.sh -c ../data/corewar -t $tm -i $out_dir/$[ $idx - 1].wave.not.txt -o $out_dir/$idx.wave"
  ./run_speed.sh -c ../data/corewar -t $tm -i $out_dir/$[ $idx - 1].wave.not.txt -o $out_dir/$idx.wave
  echo "$out_dir/$idx.wave.txt" >> $out_file
  idx=$[ $idx + 1]
  tm=$(echo "$tm * 10" | bc)
done
echo "Files not in test ❗️  : "
echo "$out_dir/$[ $idx - 1].wave.not.txt"
echo "Files for test 📂  :"
cat $out_dir/test2run
echo "Now use can run 👇  :"
echo "./run_1_tests.sh"


exit 1