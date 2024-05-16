#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution sl.cpp

compile gen_random.py

samplegroup
limits lo=1 hi=1000
sample 1
sample 2
sample 3

group 1_small 40
limits lo=1 hi=1000
tc small-1 gen_random lo=1 hi=500
tc small-2 gen_random lo=500 hi=1000
tc_manual ../manual-tests/g1.in
tc_manual ../manual-tests/g2.in
tc 1
tc 2
tc 3


group 2_equal 20
limits lo=100000000000 hi=1000000000000 eq=yes
tc equal-1 gen_random lo=100_000_000_000 hi=500_000_000_000 eq=yes
tc equal-2 gen_random lo=100_000_000_000 hi=1_000_000_000_000 eq=yes
tc equal-3 gen_random lo=100_000_000_000 hi=1_000_000_000_000 eq=yes
tc equal-4 gen_random lo=100_000_000_000 hi=1_000_000_000_000 eq=yes
tc_manual ../manual-tests/g3.in

group 3_large 40
limits lo=100000000 hi=1000000000000
include_group 2_equal
tc large-1 gen_random lo=100_000_000 hi=500_000_000
tc large-2 gen_random lo=500_000_000 hi=1_000_000_000
tc large-3 gen_random lo=1_000_000_000 hi=1_000_000_000_000
tc super-large-1 gen_random lo=100_000_000_000 hi=1_000_000_000_000
tc super-large-2 gen_random lo=100_000_000_000 hi=1_000_000_000_000
tc_manual ../manual-tests/g4.in
tc_manual ../manual-tests/g5.in
