#!/bin/sh
# /Users/wgorold/42_coreWar/test_vm/template_n_timescript/run_time.sh -f /Users/wgorold/42_coreWar/test_vm/template_n_timescript/to_run_long.sh
f_val=''

print_usage() {
  printf "Usage:\t-f file\t: set file (MUST BE)\n\n"
  printf "Like next one 👇:\n"
    printf "./run_time.sh -f ./to_run_fast.sh\n\n"
  exit 1
}

while getopts 'f:' opts; do
  case "${opts}" in
    f) f_val=${OPTARG} ;;
    *) print_usage ;;
  esac
done

#check of init vals
if [ -z "${f_val}" ]; then
    print_usage
fi

$f_val &                                    # Can be a group !!
PID=$!
(sleep 1 ; kill -9 $PID &> /dev/null) &
#(sleep 1 ; pkill -P $PID &> /dev/null) &   # For group !!
PID_KILLER=$!

# for check use:  ps aux | grep 'name of program in f_val'
wait $PID
kill -9 PID_KILLER  &> /dev/null
echo "done"

exit 1


(sleep 1 ; pkill -P $PID &> /dev/null) &
    PID_KILLER=$!

    wait $PID &> /dev/null
    pkill -P $PID_KILLER &> /dev/null