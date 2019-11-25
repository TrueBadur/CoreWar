#!/bin/sh

file_name=''
target_dir=''

print_usage() {
    printf "\nUsage:\tall options are required\n"
    printf "\t-t \t: target directory\n"
    printf "\t-f \t: file_name for output\n"
    printf "Like next one 👇:\n"
    printf "./run_init.sh -t ../data/compiled -f champ_vs_champ\n\n"
    #TODO w
    #TODO ./run_init.sh -t ../data/compiled -f ./outfiles/0.wave.non.txt
    exit 1
}

while getopts 't:f:' opts; do
  case "${opts}" in
    t) target_dir=${OPTARG} ;;
    f) file_name=${OPTARG} ;;
    *) print_usage ;;
  esac
done

#check of init vals
if [ -z "${target_dir}" ] || [ -z "${file_name}" ] ; then
    print_usage
fi

#script
champs=($target_dir/*)

rm    $file_name
touch $file_name

# iterate through array using a counter
for ((i=0; i<${#champs[@]}; i++)); do
    #do something to each element of array
    #echo "${arr[$i]}"
    for ((j=i; j<${#champs[@]}; j++)); do
        #do something to each element of array
        #echo -e "\t${arr[$j]}"
        CMD="${champs[$i]} ${champs[$j]}"
        echo $CMD
        echo $CMD >> $file_name
    done
done
exit 1