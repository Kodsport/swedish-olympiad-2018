#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution sl.cpp
compile gen_random.py

samplegroup
sample 1
sample 2
sample 3
sample 4

group grupp1 28
limits n_equals=3 maxm=10
tc small-01 gen_random n=3 m=3 sym=1 mode=nowrap
tc small-02 gen_random n=3 m=6 sym=1 mode=nowrap
tc small-03 gen_random n=3 m=6 sym=2 mode=nowrap
tc small-04 gen_random n=3 m=10 sym=5 mode=nowrap
tc small-05 gen_random n=3 m=9 sym=3 mode=nowrap
tc small-06 gen_random n=3 m=9 sym=3 extra=1 mode=nowrap
tc small-07 gen_random n=3 m=2 sym=2 extra=7 mode=nowrap
tc small-skipfirst-01 gen_random n=3 m=6 sym=3 mode=nowrap error=skipfirst
tc small-skipaday-01 gen_random n=3 m=9 sym='3' error=skipaday
tc small-wrong-01 gen_random n=3 m=6 sym=3 error=wrong

group grupp2 35
include_group grupp1
limits maxn=1000 maxm=1000
tc medium-01 gen_random n=10 m=1000 sym=1
tc medium-02 gen_random n=10 m=1000 sym=2
tc medium-03 gen_random n=37 m=1000 sym=100
tc medium-04 gen_random n=37 m=900 extra=1 sym=100
tc medium-05 gen_random n=37 m=1000 extra=-1 sym=100
tc medium-06 gen_random n=900 m=900 sym=900
tc medium-07 gen_random n=500 m=900 extra=1 sym=450
tc medium-08 gen_random n=100 m=900 sym=2 mode=nowrap
tc medium-09 gen_random n=900 m=0 sym=1 extra=1000
tc medium-skipfirst-01 gen_random n=800 m=900 sym='900//4' error=skipfirst
tc medium-skipfirst-02 gen_random n=10 m=900 sym='900//4' extra=50 error=skipfirst
tc medium-skipaday-01 gen_random n=100 m=900 sym='900//4' error=skipaday
tc medium-wrong-01 gen_random n=100 m=900 sym='900//4' error=wrong
tc medium-wrong-02 gen_random n=100 m=900 sym='900//4' error=wrong-small

group grupp3 37
include_group grupp2
include_group sample
tc large-01 gen_random n=1000000 m=2400 sym=2400
tc large-02 gen_random n=900000 m=2400 sym='2400//2'
tc large-03 gen_random n=1000000 m=2400 sym='2400//4' extra=1
tc large-04 gen_random n=10 m=2400 sym=1
tc large-05 gen_random n=10 m=2400 sym=2
tc large-06 gen_random n=1000000 m=100 sym=1
tc large-07 gen_random n=1000000 m=100 sym=4
tc large-08 gen_random n=73 m=2400 sym=100
tc large-09 gen_random n=75 m=2400 extra=1 sym=100
tc large-10 gen_random n=1000000 m=2400 sym=240
tc large-11 gen_random n=100 m=2400 sym=2 mode=nowrap
tc large-12 gen_random n=1000000 m=2400 sym='2400//4' extra=600
tc large-13 gen_random n=2400 m=2400 sym='2400//4' extra=-7
tc large-14 gen_random n=10 m=2400 sym='2400//4' extra=-1
tc large-15 gen_random n=10000 m=1 sym=1
tc large-skipfirst-01 gen_random n=1000000 m=2400 sym='2400//4' error=skipfirst
tc large-skipfirst-02 gen_random n=10 m=2400 sym='2400//4' extra=500 error=skipfirst
tc large-skipfirst-03 gen_random n=1000 m=1 sym=1 error=skipfirst
tc large-skipaday-01 gen_random n=100000 m=2400 sym='2400//4' error=skipaday
tc large-wrong-01 gen_random n=1000000 m=2400 sym='2400//4' error=wrong
tc large-wrong-02 gen_random n=86400 m=3000 sym=1 error=wrong-small
tc large-wrong-03 gen_random n=86400 m=2400 sym='2400//4' error=wrong-small
tc large-wrong-04 gen_random n=1000 m=2400 sym='2400//4' error=wrong-small
