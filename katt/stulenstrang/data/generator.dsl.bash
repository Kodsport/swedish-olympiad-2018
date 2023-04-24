#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution ng_100_faster.cpp
compile gen_random.py
compile gen_min.py
compile gen_max.py

group grupp1 10
tc g1-01 gen_max n=4 k=2
tc g1-02 gen_min n=8 k=2 perturb=10
tc g1-03 gen_min n=1000 k=2
tc g1-04 gen_random n=1000 k=2
tc g1-05 gen_random n=100000 k=2
tc g1-06 gen_random n=100000 k=2
tc g1-07 gen_random n=100000 k=2
tc g1-08 gen_min n=100000 k=2 perturb=10
tc g1-09 gen_min n=4 k=2
tc g1-10 gen_max n=100000 k=2
tc g1-11 gen_random n=100000 k=2 impossible=1
tc g1-12 gen_random n=999 k=2

group grupp2 20
tc g2-01 gen_random n=6 k=3
tc g2-02 gen_min n=8 k=3 perturb=5
tc g2-03 gen_min n=1000 k=3
tc g2-04 gen_random n=1000 k=3
tc g2-05 gen_random n=100000 k=3
tc g2-06 gen_random n=100000 k=3
tc g2-07 gen_random n=100000 k=3
tc g2-08 gen_min n=100000 k=3 perturb=10
tc g2-09 gen_min n=6 k=3
tc g2-10 gen_max n=100000 k=3
tc g2-11 gen_random n=100000 k=3 impossible=1
tc g2-12 gen_random n=999 k=3

group grupp3 10
tc g3-01 gen_random n=10 k=5
tc g3-02 gen_random n=20 k=2
tc g3-03 gen_random n=20 k=5
tc g3-04 gen_random n=20 k=6
tc g3-05 gen_random n=20 k=7
tc g3-06 gen_random n=20 k=8
tc g3-07 gen_random n=20 k=9
tc g3-08 gen_random n=20 k=10
tc g3-09 gen_max n=20 k=10
tc g3-10 gen_min n=20 k=10
tc g3-11 gen_random n=20 k=7 impossible=1
tc g3-12 gen_random n=19 k=9

group grupp4 15
tc g4-01 gen_random n=12 k=6
tc g4-02 gen_random n=40 k=2
tc g4-03 gen_random n=40 k=4
tc g4-04 gen_random n=40 k=6
tc g4-05 gen_random n=40 k=6
tc g4-06 gen_min n=40 k=6
tc g4-07 gen_max n=40 k=6
tc g4-08 gen_max n=40 k=6 perturb=5
tc g4-09 gen_random n=40 k=6 impossible=1

group grupp5 45
include_group grupp3
include_group grupp4
tc g5-01 gen_random n=24 k=12
tc g5-02 gen_random n=40 k=12
tc g5-03 gen_random n=40 k=12
tc g5-04 gen_random n=40 k=12
tc g5-05 gen_min n=40 k=12 perturb=5
tc g5-06 gen_max n=40 k=12 perturb=5
tc g5-07 gen_min n=24 k=12
tc g5-08 gen_max n=24 k=12

cleanup_programs
