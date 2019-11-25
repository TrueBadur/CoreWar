#!/bin/bash

corewar_my="../corewar"
corewar_origin="../data/corewar"

folder="../data/compiled"
path=$folder

tests=($(ls $path | grep ".cor$"))

##сюда сохранятся уже проверенные комбинации
watched="./done.txt"
##сюда сохранятся несоответствующие результаты
errors="./errors.txt"

##rm -rf $save
##rm -rf $save1

touch $watched
touch $errors

number=(1 20 50 80 150 200 600 800 1400 2400 3000 4400 4450 5000 8000 10000 15000)
##number=(1000 5000 10000 15000 17000)

for file1 in "${tests[@]}"
do
	for file2 in "${tests[@]}"
	do
		need_check=$(cat $watched | grep "$file1 $file2" | wc -l)
		if [ "$need_check" -eq "0" ]
		then
			echo "_$file1 $file2"

			##for (( c=1; c<=50; c++ ))
			for c in ${!number[@]}
			do
				##let num=7100+c*1
				num="${number[$c]}"

				my=$(./$corewar_my -dump $num $path/$file1 $path/$file2 | tail -n 64 | cut -d':' -f2 | tr -d '\n' | tr -d ' ')
				notmy=$(./$corewar_origin -d $num $path/$file1 $path/$file2 | tail -n 64 | cut -d':' -f2 | tr -d '\n' | tr -d ' ')

				if [ "$my" == "$notmy" ]
				then
					echo "$file1 $file2	$num: идентичны."
				else
					echo "$path/$file1 $path/$file2	$num: имеют различия."
					diff  <(echo "$my" ) <(echo "$notmy")
					echo "Итерация $num $file1 $file2" >> $errors
					##exit 0;
				fi
			done
			echo "$file1 $file2" >> $watched
		fi
	done
done
