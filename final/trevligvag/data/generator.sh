#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution sl.cpp
compile gen_random.py

samplegroup
limits maxn=10 maxm=20
sample 1
sample 2

group grupp1 21
limits maxn=10 maxm=20
tc small-01 gen_random n=10 m=20 graph=random-long weights=prefer-small seed=123
tc small-02 gen_random n=10 m=20 graph=random-very-long weights=prefer-small seed=126
tc small-03 gen_random n=10 m=20 graph=random-long weights=uniform seed=139 # length 9
tc small-04 gen_random n=10 m=20 graph=random weights=uniform seed=135 # length 5
tc small-05 gen_random n=10 m=20 graph=random weights=uniform seed=291 # length 2
tc small-06 gen_random n=10 m=20 graph=random weights=uniform seed=294 # length 4
tc small-07 gen_random n=10 m=1 graph=line-perturbed weights=uniform
tc small-08 gen_random n=10 m=3 graph=line-perturbed weights=uniform

group grupp2 41
limits maxn=1000 maxm=2000
include_group grupp1
tc medium-01 gen_random n=100 m=1000 graph=random-long weights=prefer-small
tc medium-02 gen_random n=1000 m=2000 graph=random-long weights=prefer-small seed=137
tc medium-03 gen_random n=1000 m=2000 graph=random-long weights=prefer-small seed=138
tc medium-04 gen_random n=1000 m=2000 graph=random-long weights=uniform seed=138
tc medium-05 gen_random n=1000 m=2000 graph=random-long weights=uniform seed=259
tc medium-06 gen_random n=500 m=2000 graph=random weights=uniform seed=291
tc medium-07 gen_random n=1000 m=0 graph=line weights=uniform
tc medium-08 gen_random n=1000 m=0 graph=line weights=prefer-small
tc medium-09 gen_random n=1000 m=100 graph=line-perturbed weights=uniform
tc medium-10 gen_random n=1000 m=1000 graph=line-perturbed weights=uniform

group grupp3 38
limits maxn=100000 maxm=200000
include_group grupp2
include_group sample
tc large-01 gen_random n=1000 m=100000 graph=random-long weights=prefer-small
tc large-02 gen_random n=100000 m=200000 graph=random-long weights=prefer-small seed=281
tc large-03 gen_random n=100000 m=200000 graph=random-long weights=prefer-small seed=218
tc large-04 gen_random n=100000 m=200000 graph=random-very-long weights=prefer-small seed=50
tc large-05 gen_random n=100000 m=200000 graph=random-long weights=uniform seed=217
tc large-06 gen_random n=50000 m=200000 graph=random weights=uniform seed=280
tc large-07 gen_random n=100000 m=0 graph=line weights=uniform
tc large-08 gen_random n=100000 m=0 graph=line weights=prefer-small
tc large-09 gen_random n=100000 m=10000 graph=line-perturbed weights=uniform
tc large-10 gen_random n=100000 m=100000 graph=line-perturbed weights=uniform

