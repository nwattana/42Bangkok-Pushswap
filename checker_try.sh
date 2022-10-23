#!/bin/bash

ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
NAME=push_swap


./$NAME $ARG | ./checker_Mac $ARG
./$NAME $ARG | wc -l
