#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution js.py
compile gen.py

samplegroup
limits group=sample
sample 1
sample 2
sample 3

group g1 40
limits group=g1
tc_manual poster

# We choose sufficient seed such that the answer is not loop
group g2 30
limits group=g2
include_group g1
tc 1
tc 2
tc_manual g21
tc_manual g22
tc_manual g23
tc_manual g24


group g3 30
limits group=g3
include_group g2
tc 3
tc g3-1 gen seed=4
tc g3-2 gen seed=10
tc g3-3 gen seed=8


