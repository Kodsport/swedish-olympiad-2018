#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution sl.cpp

compile gen_random.py

samplegroup
sample 1
sample 2
sample 3

group 1_no1groups 20
tc no1-1 gen_random mask=0111
tc no1-2 gen_random mask=0111
tc_manual ../manual-tests/g1.in
tc 3

group 2_no2groups 20
tc no2-1 gen_random mask=1011
tc no2-2 gen_random mask=1011
tc_manual ../manual-tests/g2.in

group 3_no3groups 20
tc no3-1 gen_random mask=1101
tc no3-2 gen_random mask=1101
tc_manual ../manual-tests/g3.in

group 4_all 40
include_group 1_no1groups
include_group 2_no2groups
include_group 3_no3groups
tc all-1 gen_random mask=1111
tc all-2 gen_random mask=1111
tc_manual ../manual-tests/g4.in
tc_manual ../manual-tests/g5.in
tc 1
tc 2
