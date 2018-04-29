#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution sl.cpp
compile gen_random.py

samplegroup
sample 1
sample 2

# 2 <= n <= 20
group grupp1 12
tc small-01 gen_random n=10 k=20 lo=1 hi=10
tc small-02 gen_random n=20 k=10000 lo=1 hi=1000
tc small-03 gen_random n=20 k=10000 lo=1 hi=100000
tc small-04 gen_random n=20 k=10000 lo=1 hi=10000000 dist=exp
tc small-05 gen_random n=20 k=100000000 lo=1 hi=10000000
tc small-06 gen_random n=20 k=1000000000 lo=1 hi=10000000
tc small-07 gen_random n=20 k=1000000000 lo=1 hi=10000000 dist=same

# 2 <= n <= 1000
group grupp2 17
include_group grupp1
tc medium-01 gen_random n=1000 k=0 lo=1 hi=10
tc medium-02 gen_random n=1000 k=5 lo=1 hi=10
tc medium-03 gen_random n=1000 k=2000000 lo=1 hi=10
tc medium-04 gen_random n=1000 k=2000000 lo=1 hi=1000
tc medium-05 gen_random n=1000 k=2000000 lo=1 hi=1000 dist=exp
tc medium-06 gen_random n=1000 k=70000 lo=1 hi=1000 dist=exp
tc medium-07 gen_random n=1000 k=2000000000 lo=1 hi=1000
tc medium-08 gen_random n=1000 k=2000000000 lo=1 hi=1000 dist=exp
tc medium-09 gen_random n=1000 k=1000 lo=1 hi=1000
tc medium-10 gen_random n=1000 k=1000 lo=1 hi=1000 dist=exp
tc medium-11 gen_random n=1000 k=2000000000 lo=1 hi=10000000 dist=exp
tc medium-12 gen_random n=1000 k=2000000000 lo=1 hi=10000000

# k <= 1000, r_i <= 1000
group grupp3 25
tc lowcost-01 gen_random n=400000 k=1000 lo=1 hi=1000
tc lowcost-02 gen_random n=400000 k=1000 lo=1 hi=1000 dist=exp
tc lowcost-03 gen_random n=400000 k=10 lo=1 hi=1000
tc lowcost-04 gen_random n=400000 k=10 lo=1 hi=1000 dist=exp
tc lowcost-05 gen_random n=400000 k=1000 lo=1 hi=1
tc lowcost-06 gen_random n=400000 k=1000 lo=1 hi=2
tc lowcost-07 gen_random n=400000 k=1000 lo=1 hi=5

# All r_i are the same
group grupp4 23
tc same-01 gen_random n=10 k=50 lo=1 hi=10 dist=same
tc same-02 gen_random n=10 k=0 lo=1 hi=10 dist=same
tc same-03 gen_random n=10 k=50 lo=1 hi=6 dist=same
tc same-04 gen_random n=400000 k=1000000000 lo=1 hi=1000 dist=same
tc same-05 gen_random n=400000 k=1000000000 lo=1 hi=10000000 dist=same
tc same-06 gen_random n=400000 k=1000 lo=1 hi=100000 dist=same
tc same-07 gen_random n=400000 k=2000000000 lo=1 hi=1 dist=same
tc same-08 gen_random n=400000 k=1000000 lo=1 hi=1 dist=same

# No further constraints
group grupp5 23
include_group grupp2
include_group grupp3
include_group grupp4
tc large-01 gen_random n=400000 k=8 lo=1 hi=10
tc large-02 gen_random n=400000 k=2000000 lo=1 hi=10
tc large-03 gen_random n=400000 k=2000000000 lo=1 hi=1000
tc large-04 gen_random n=400000 k=2000000000 lo=1 hi=1000 dist=exp
tc large-05 gen_random n=400000 k=2000000000 lo=1 hi=10 dist=exp
tc large-06 gen_random n=400000 k=700000 lo=1 hi=1000 dist=exp
tc large-07 gen_random n=400000 k=1000 lo=1 hi=1000 dist=exp
tc large-08 gen_random n=400000 k=2000000000 lo=1 hi=10000000 dist=exp

cleanup_programs
