#!/usr/bin/env bash
. ../../../testdata_tools/gen.sh

use_solution js.cpp

compile gen_random.py

samplegroup
sample 1
sample 2

group 1_short 60
limits n=10
tc_manual ../manual-tests/g1.in
tc_manual ../manual-tests/g2.in
tc_manual ../manual-tests/g3.in
tc small-1 gen_random n=10
tc small-2 gen_random n=10
tc small-3 gen_random n=10
tc 1
tc 2

group 2_all 40
limits n=15
include_group 1_short
tc_manual ../manual-tests/g4.in
tc_manual ../manual-tests/g5.in
tc large-1 gen_random n=15
tc large-2 gen_random n=15