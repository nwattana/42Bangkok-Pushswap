#!/bin/bash

if [ $# -eq 1 ]
then
	echo $0
	ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
else
	echo -e "defult 100"
	ARG=$(ruby -e "puts (-50..49).to_a.shuffle.join(' ')")
fi
echo -e "new:" $ARG "\n" >> log.txt
#./push_swap_test $ARG | wc -l | tee -a log.txt
#./push_swap_test $ARG
./push_swap_test $ARG | ./checker_linux $ARG
