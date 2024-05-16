#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution js.cpp

compile gen.py
compile gensingle.py

samplegroup
limits maxn=10 maxcat=10
sample 1
sample 2

group 1_smallNAnd1Cat 20
limits maxn=10 maxcat=1
tc_manual ../manual-tests/g1.in
tc rnd-single-1 gensingle n=10 prob=0.1
tc rnd-single-2 gensingle n=10 prob=0.1
tc rnd-single-3 gensingle n=10 prob=0.2
tc rnd-single-4 gensingle n=10 prob=0.5
tc rnd-single-5 gensingle n=10 prob=0.5
tc rnd-single-6 gensingle n=10 prob=0.9
tc rnd-single-7 gensingle n=10 prob=0.9

group 2_smallN 40
limits maxn=10 maxcat=10
include_group 1_smallNAnd1Cat
tc rnd-small-1 gen n=10 prob=0.1
tc rnd-small-2 gen n=10 prob=0.1
tc rnd-small-3 gen n=10 prob=0.2
tc rnd-small-4 gen n=10 prob=0.5
tc rnd-small-5 gen n=10 prob=0.5
tc rnd-small-6 gen n=10 prob=0.9
tc rnd-small-7 gen n=10 prob=0.9
tc_manual ../manual-tests/g2.in
tc_manual ../manual-tests/g3.in
tc 1
tc 2

group 3_all 40
limits maxn=30 maxcat=10
include_group 2_smallN
tc rnd-1 gen n=30 prob=0.1
tc rnd-2 gen n=30 prob=0.1
tc rnd-3 gen n=30 prob=0.2
tc rnd-4 gen n=30 prob=0.5
tc rnd-5 gen n=30 prob=0.5
tc rnd-6 gen n=30 prob=0.9
tc rnd-7 gen n=30 prob=0.9
tc_manual ../manual-tests/g4.in
tc_manual ../manual-tests/g5.in
