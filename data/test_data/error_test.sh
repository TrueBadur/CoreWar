#!/bin/bash

PATH_ASM_ORG=../asm
PATH_ASM=../../cmake-build-debug/asm
PATH_TEST=./error/

o_flag=''
c_flag=''
while getopts 'oc' flag; do
  case "${flag}" in
    o) o_flag='true' ;;
    c) c_flag='true' ;;
  esac
done

for f in $PATH_TEST*.s
do
  clear
  echo -e "\n\033[0;107;30mProcessing $f file...\033[0m"
  cat -n $f
  echo -e "\n\033[0;36m"
  #../src/asm/build/asm $f
  if [ ! -z "${c_flag}" ]; then
    $PATH_ASM $f
    echo -e "\n\033[0;35m"
    $PATH_ASM_ORG $f
  elif [ ! -z "${o_flag}" ]; then
    $PATH_ASM_ORG $f
  else
    $PATH_ASM $f
  fi
  echo -e "\n\033[0m"
  read -p "Press enter to continue"
done
rm $PATH_TEST*.cor