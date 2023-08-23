#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution ng_100.cpp

compile generator_random.py
compile generator_tree.py
compile generator_line.py
compile generator_star.py

samplegroup
limits maxn=10 maxm=10
sample 1
sample 2
sample 3
sample 4

group grupp1 26
limits maxn=10 maxm=20
tc small-01 generator_random n=2 m=1
tc small-02 generator_random n=10 m=20
tc small-03 generator_random n=10 m=20
tc small-04 generator_random n=10 m=5
tc small-05 generator_line n=5 s=1 t=4
tc small-06 generator_tree n=10
tc small-07 generator_star n=10 star=5
tc small-08 generator_random n=10 m=0

group grupp2 35
include_group grupp1
limits maxn=200 maxm=400
tc medium-01 generator_random n=200 m=400
tc medium-02 generator_random n=200 m=400
tc medium-03 generator_random n=200 m=220
tc medium-04 generator_random n=200 m=80
tc medium-05 generator_tree n=200
tc medium-06 generator_tree n=200 height=100
tc medium-07 generator_line n=200 s=1 t=200
tc medium-08 generator_star n=200 star=195

group grupp3 39
include_group grupp2
include_group sample
limits maxn=100000 maxm=200000
tc large-01 generator_random n=100000 m=200000
tc large-02 generator_random n=100000 m=200000
tc large-03 generator_random n=100000 m=110000
tc large-04 generator_random n=100000 m=20000
tc large-05 generator_random n=1000 m=200000
tc large-06 generator_tree n=100000
tc large-07 generator_tree n=100000 height=50000
tc large-08 generator_line n=100000 s=1 t=100000
tc large-09 generator_star n=100000 star=97900
