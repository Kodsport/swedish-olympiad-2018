#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution js.cpp

samplegroup
limits maxn=30 maxcat=10
sample 1
sample 2

group group1 20
limits maxn=10 maxcat=1
tc_manual ../manual/g1.in

group group2 20
limits maxn=10 maxcat=10
tc_manual ../manual/g2.in

group group3 20
limits maxn=10 maxcat=10
tc_manual ../manual/g3.in

group group4 20
limits maxn=30 maxcat=10
tc_manual ../manual/g4.in

group group5 20
limits maxn=30 maxcat=10
tc_manual ../manual/g5.in
