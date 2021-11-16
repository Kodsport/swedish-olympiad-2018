#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution js.cpp

compile gen.py
compile gensingle.py

samplegroup
limits maxn=30 maxcat=10
sample 1
sample 2

group group1 20
limits maxn=10 maxcat=1
tc_manual ../manual/g1.in
tc rnd-single-1 gensingle n=10 prob=0.1
tc rnd-single-2 gensingle n=10 prob=0.1
tc rnd-single-3 gensingle n=10 prob=0.2
tc rnd-single-4 gensingle n=10 prob=0.5
tc rnd-single-5 gensingle n=10 prob=0.5
tc rnd-single-6 gensingle n=10 prob=0.9
tc rnd-single-7 gensingle n=10 prob=0.9

group group2 40
limits maxn=10 maxcat=10
tc 1
tc 2
tc_manual ../manual/g2.in
tc_manual ../manual/g3.in
tc rnd-small-1 gen n=10 prob=0.1
tc rnd-small-2 gen n=10 prob=0.1
tc rnd-small-3 gen n=10 prob=0.2
tc rnd-small-4 gen n=10 prob=0.5
tc rnd-small-5 gen n=10 prob=0.5
tc rnd-small-6 gen n=10 prob=0.9
tc rnd-small-7 gen n=10 prob=0.9

group group3 40
limits maxn=30 maxcat=10
tc_manual ../manual/g4.in
tc_manual ../manual/g5.in
tc rnd-1 gen n=30 prob=0.1
tc rnd-2 gen n=30 prob=0.1
tc rnd-3 gen n=30 prob=0.2
tc rnd-4 gen n=30 prob=0.5
tc rnd-5 gen n=30 prob=0.5
tc rnd-6 gen n=30 prob=0.9
tc rnd-7 gen n=30 prob=0.9
