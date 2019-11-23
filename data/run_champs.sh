#!/bin/bash

PATH_ASM_ORG=./asm
PATH_ASM=../cmake-build-debug/asm
CHS="./champs"

o_flag=''
c_flag=''
while getopts 'oc' flag; do
  case "${flag}" in
    o) o_flag='true' ;;
    c) c_flag='true' ;;
  esac
done

echo ""
echo "-o for run original asm"
echo "-c for run both"
echo -e "-t run tmp_test.s in root of this folder. example: \033[0;36m./run_test.sh -c -t\033[0m"
echo ""

for f in $CHS/*.s
do
  clear
  echo -e "\n\033[0;107;30mProcessing $f file...\033[0m"
  #cat -n $f
  echo -e "\n\033[0;36m"
  #../old/asm/build/asm $f
  if [ ! -z "${c_flag}" ]; then
    $PATH_ASM_ORG $f
    mv $(dirname $f)/$(basename $f .s).cor $(dirname $f)/org_$(basename $f .s).cor
    echo -e "\n\033[0;35m"
    $PATH_ASM $f
    echo $(dirname $f)/$(basename $f .s).cor vs $(dirname $f)/org_$(basename $f .s).cor
    cmp -l $(dirname $f)/$(basename $f .s).cor $(dirname $f)/org_$(basename $f .s).cor
  elif [ ! -z "${o_flag}" ]; then
    $PATH_ASM_ORG $f
  else
    $PATH_ASM $f
  fi
  echo -e "\n\033[0m"
  read -p "Press enter to continue"
done
rm $CHS/*.cor