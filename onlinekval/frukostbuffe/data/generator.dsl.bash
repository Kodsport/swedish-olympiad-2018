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

# $2 \le N \le 100$ & , $0 \le a_i \le 100$.
group g1small 25
limits maxn=100 amin=0
tc 1
tc 2
tc small-01 gen_random n=100 minv=0 maxv=100
tc small-02 gen_random n=100 minv=0 maxv=100
tc small-03 gen_random n=100 minv=0 maxv=100

# & $2 \le N \le 1000$ & , $0 \le a_i \le 100$.
group g2medium 25
include_group g1small
limits maxn=1000 amin=0
tc medium-01 gen_random n=1000 minv=0 maxv=100
tc medium-02 gen_random n=1000 minv=0 maxv=100
tc medium-03 gen_random n=1000 minv=0 maxv=100
tc medium-04 gen_random n=200 minv=0 maxv=100 padl=800

# $2 \le N \le 500\,000$ & , $0 \le a_i \le 100$.
group g3large 25
limits amin=0
include_group g2medium
tc large-01 gen_random n=300000 minv=0 maxv=100
tc large-02 gen_random n=300000 minv=0 maxv=100
tc large-03 gen_random n=300000 minv=0 maxv=100
tc large-04 gen_random n=100000 minv=0 maxv=100 padl=200000

# $2 \le N \le 500\,000$ & , $-100 \le a_i \le 100$.
group g4neg 25
include_group g3large
tc 3
tc 4
tc neg-01 gen_random n=300000 minv=-100 maxv=100 # balanced random, ans will be pretty random
tc neg-02 gen_random n=300000 minv=-100 maxv=100
tc neg-03 gen_random n=300000 minv=-99 maxv=100 # more positive than negative, ans will be to take middle and then roughly everything
tc neg-04 gen_random n=300000 minv=-97 maxv=100
tc neg-05 gen_random n=300000 minv=-93 maxv=100
tc neg-06 gen_random n=300000 minv=-100 maxv=99 # more negative than positive, ans will be to take some random value and then a few things to either side
tc neg-07 gen_random n=300000 minv=-100 maxv=97
tc neg-08 gen_random n=300000 minv=-100 maxv=93
tc neg-09 gen_random n=300000 minv=-100 maxv=-10 # have to pick something, ans = -10


