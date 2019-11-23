#!/bin/sh
#v0.0.1

a_flag=''
b_flag=''
f_val=''

print_usage() {
  printf "Usage:\t-a \t: flag_a\n"
  printf "\t-b \t: flag_b\n"
  printf "\t-f file\t: set file (MUST BE)\n"
  exit 1
}

while getopts 'abf:' opts; do
  case "${opts}" in
    a) a_flag='true' ;;
    b) b_flag='true' ;;
    f) f_val=${OPTARG} ;;
    *) print_usage ;;
  esac
done

#check of init vals
if [ -z "${f_val}" ]; then
    print_usage
fi

#script
echo "hello_script"
echo "f_val=$f_val"
if [ ! -z "${a_flag}" ]; then
    echo "flag_A"
fi
if [ ! -z "${b_flag}" ]; then
    echo "flag_B"
fi