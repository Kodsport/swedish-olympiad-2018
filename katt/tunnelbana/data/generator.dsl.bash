#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution ng_100.cpp
compile gen_random.py
compile gen_star.py

samplegroup
limits maxn=10 maxm=10
sample 1
sample 2

group grupp1 19
limits maxn=50 maxm=50
tc g1-01 gen_random n=50 m=50 k=2
tc g1-02 gen_random n=50 m=50 k=6
tc g1-03 gen_random n=50 m=50 k=0
tc g1-04 gen_random n=50 m=0 k=0
tc g1-05 gen_random n=50 m=50 k=100000
tc g1-06 gen_random n=2 m=50 k=47
tc g1-07 gen_random n=50 m=50 k=2 height=35
tc g1-08 gen_random n=50 m=50 k=100000 height=35
tc g1-09 gen_random n=50 m=50 k=21 height=46
tc g1-10 gen_star n=50 m=50 k=2

group grupp2 26
limits maxn=1000 maxm=1000
include_group grupp1
tc g2-01 gen_random n=1000 m=1000 k=2
tc g2-02 gen_random n=1000 m=1000 k=10
tc g2-03 gen_random n=1000 m=1000 k=0
tc g2-04 gen_random n=1000 m=1000 k=100000
tc g2-05 gen_random n=1000 m=1000 k=2 height=750
tc g2-06 gen_random n=1000 m=1000 k=0 height=750
tc g2-07 gen_random n=1000 m=1000 k=300 height=750
tc g2-08 gen_random n=1000 m=1000 k=450 height=950
tc g2-09 gen_star n=1000 m=1000 k=2

group grupp3 20
limits maxn=20000 maxm=1000
include_group grupp2
tc g3-01 gen_random n=20000 m=1000 k=3
tc g3-02 gen_random n=20000 m=1000 k=15
tc g3-03 gen_random n=20000 m=1000 k=0
tc g3-04 gen_random n=20000 m=1000 k=100000
tc g3-05 gen_random n=20000 m=1000 k=3 height=3000
tc g3-06 gen_random n=20000 m=1000 k=400 height=10000
tc g3-07 gen_random n=20000 m=1000 k=500 height=17000
tc g3-08 gen_star n=20000 m=1000 k=1

group grupp4 35
limits maxn=100000 maxm=100000
include_group grupp3
include_group sample
tc g4-01 gen_random n=100000 m=100000 k=15
tc g4-02 gen_random n=100000 m=100000 k=15
tc g4-03 gen_random n=100000 m=100000 k=0
tc g4-04 gen_random n=100000 m=100000 k=100000
tc g4-05 gen_random n=100000 m=100000 k=5
tc g4-06 gen_random n=100000 m=100000 k=5 height=75000
tc g4-07 gen_random n=100000 m=100000 k=30000 height=75000
tc g4-08 gen_random n=100000 m=100000 k=80000 height=80000
tc g4-09 gen_random n=100000 m=100000 k=99999 height=99000
tc g4-10 gen_star n=100000 m=100000 k=2
