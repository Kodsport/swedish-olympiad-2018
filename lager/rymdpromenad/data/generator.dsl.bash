#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh


use_solution ng_100.cpp
compile gen_random.py
compile gen_ap.py
compile gen_alternating.py
compile gen_opposite.py

samplegroup
sample 1
sample 2
sample 3

group grupp1 10
limits maxn=10 maxm=10
tc 1
tc 2
tc 3
tc g1-01 gen_random n=10 m=10
tc g1-02 gen_random n=10 m=10
tc g1-03 gen_random n=10 m=1
tc g1-04 gen_random n=3 m=10
tc g1-05 gen_opposite n=10 m=10
tc g1-06 gen_ap n=10 m=10 diff=-1
tc g1-07 gen_ap n=10 m=10 diff=1
tc g1-08 gen_alternating n=10 m=10 a=2 b=2

group grupp2 24
limits maxn=100 maxm=100
include_group grupp1
tc g2-01 gen_random n=100 m=100
tc g2-02 gen_random n=99 m=99
tc g2-03 gen_random n=10 m=100
tc g2-04 gen_opposite n=100 m=100
tc g2-05 gen_opposite n=100 m=100 diff=5
tc g2-06 gen_ap n=100 m=100 diff=-1
tc g2-07 gen_ap n=100 m=100 diff=1
tc g2-08 gen_ap n=100 m=100 diff=37
tc g2-09 gen_alternating n=100 m=100

group grupp3 19
limits maxn=100000 maxm=1000
include_group grupp2
tc g3-01 gen_random n=100000 m=1000
tc g3-02 gen_random n=99999 m=999
tc g3-03 gen_random n=11 m=1000
tc g3-04 gen_opposite n=100000 m=1000
tc g3-05 gen_opposite n=100000 m=1000 diff=500
tc g3-06 gen_ap n=100000 m=1000 diff=-1
tc g3-07 gen_ap n=100000 m=1000 diff=1
tc g3-08 gen_ap n=100000 m=1000 diff=77777
tc g3-09 gen_alternating n=100000 m=1000

group grupp4 47
include_group grupp3
tc g5-01 gen_random n=100000 m=100000
tc g5-02 gen_random n=100000 m=100000
tc g5-03 gen_random n=99999 m=99999
tc g5-04 gen_random n=11 m=100000
tc g5-05 gen_opposite n=100000 m=100000
tc g5-06 gen_opposite n=100000 m=100000 diff=500
tc g5-07 gen_ap n=100000 m=100000 diff=-1
tc g5-08 gen_ap n=100000 m=100000 diff=1
tc g5-09 gen_ap n=100000 m=100000 diff=77777
tc g5-10 gen_alternating n=100000 m=99999
tc g5-11 gen_alternating n=100000 m=100000

