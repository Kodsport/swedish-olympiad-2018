#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution js.cpp

compile gen_random.py

samplegroup
limits lo=3 hi=6 max_ai=30
sample 1
sample 2
sample 3

group group01 20
limits lo=3 hi=3 max_ai=20
tc low-max1 gen_random lo=3 hi=3 max_ai=5
tc low-max2 gen_random lo=3 hi=3 max_ai=5
tc g1-max1 gen_random lo=3 hi=3 n=3 max_ai=20
tc g1-max2 gen_random lo=3 hi=3 n=3 max_ai=20
tc_manual ../manual-tests/g1.in
tc 2

group group02 20
limits lo=3 hi=5 max_ai=100
tc g2-max1 gen_random lo=3 hi=5 n=5 max_ai=100
tc g2-max2 gen_random lo=3 hi=5 n=5 max_ai=100
tc g2-max3 gen_random lo=3 hi=5 n=5 max_ai=100
tc_manual ../manual-tests/g2.in
tc 1

group group03 20
limits lo=5 hi=10 max_ai=1000
tc g3-max1 gen_random lo=5 hi=10 n=5 max_ai=1000
tc g3-max2 gen_random lo=5 hi=10 n=10 max_ai=1000
tc g3-max3 gen_random lo=5 hi=10 n=10 max_ai=1000
tc_manual ../manual-tests/g3.in
tc 3

group group04 40
limits lo=10 hi=20 max_ai=3000
tc g4-max1 gen_random lo=10 hi=20 n=10 max_ai=3000
tc g4-max2 gen_random lo=10 hi=20 n=15 max_ai=3000
tc g4-max3 gen_random lo=10 hi=20 n=20 max_ai=3000
tc g4-max4 gen_random lo=10 hi=20 max_ai=3000
tc_manual ../manual-tests/g4.in
tc_manual ../manual-tests/g5.in
