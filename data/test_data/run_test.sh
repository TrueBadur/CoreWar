#!/bin/bash

PATH_ASM_ORG=../asm
PATH_ASM=../../asm
names=(./test_files/*)
CHS=""

o_flag=''
c_flag=''
t_flag=''
while getopts 'oct' flag; do
  case "${flag}" in
    o) o_flag='true' ;;
    c) c_flag='true' ;;
    t) t_flag='true' ;;
  esac
done

echo ""
echo "-o for run original asm"
echo "-c for run both"
echo -e "-t run tmp_test.s in root of this folder. example: \033[0;36m./run_test.sh -c -t\033[0m"
echo ""

if [ -z "${t_flag}" ]; then
  PS3="Please enter path: "
  select name in "${names[@]}"; do
      echo "You have chosen $name"
      CHS=$name
      break
  done
  else
    CHS=.
fi

for f in $CHS/*.s
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
rm $CHS/*.cor
