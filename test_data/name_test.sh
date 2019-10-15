#!/bin/bash

PATH_ASM_ORG=../data/asm
PATH_ASM=../src/asm/build/asm
PATH_TEST=./test_data_name/

o_flag=''
while getopts 'o' flag; do
  case "${flag}" in
    o) o_flag='true' ;;
  esac
done

for f in $PATH_TEST*.s
do
  clear
  echo -e "\n\033[0;107;30mProcessing $f file...\033[0m"
  cat $f
  echo -e "\n\033[0;36m"
  #../src/asm/build/asm $f
  if [ -z "${o_flag}" ]; then
    $PATH_ASM $f
  else
    $PATH_ASM_ORG $f
  fi
  echo -e "\n\033[0m"
  read -p "Press enter to continue"
done
rm $PATH_TEST*.cor