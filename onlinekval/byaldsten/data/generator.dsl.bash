#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution nils_100.cpp
compile gen_random.py

samplegroup
sample 1
sample 2
sample 3

group g1small 30
limits maxn=1000
tc 1
tc 2
tc 3
tc small-01 gen_random n=1000
tc small-02 gen_random n=1000
tc small-03 gen_random n=1000 max=100000 maxage=100
tc small-04 gen_random n=1000 max=10000 maxage=100
tc small-05 gen_random n=1000 maxage=1
tc small-06 gen_random n=1000 minage=10 maxage=10
tc small-07 gen_random n=1

group g2sameage 25
limits samesmallage=1
tc sameage-01 gen_random n=100000 max=200000 minage=100000 maxage=100000
tc sameage-02 gen_random n=100000 max=100000 minage=200000 maxage=200000
tc sameage-03 gen_random n=100000 max=200000 minage=10000 maxage=10000
tc sameage-04 gen_random n=100000 max=200000 minage=1000 maxage=1000
tc sameage-05 gen_random n=100000 max=290000 minage=10 maxage=10
tc sameage-06 gen_random n=100000 max=100000 minage=1 maxage=1
tc sameage-07 gen_random n=1 max=200000 maxage=100000

group g3large 45
include_group g1small
include_group g2sameage
tc large-01 gen_random n=100000
tc large-02 gen_random n=100000
tc large-03 gen_random n=100000
tc large-04 gen_random n=100000 maxage=10000
tc large-05 gen_random n=100000 maxage=1000
tc large-06 gen_random n=100000 max=100003 maxage=10
tc large-07 gen_random n=100000 max=100003
tc large-08 gen_random n=100000 max=200000 minage=999690000 maxage=999700000
tc large-09 gen_random n=100000 max=200000 minage=999699900 maxage=999700000

