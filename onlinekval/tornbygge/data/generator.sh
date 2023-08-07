#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution dpSegTree.cpp
compile generator.py

samplegroup
sample 1
sample 2
sample 3

group g1 19
limits wdecr=1 maxn=10 maxh=100000
tc 1
tc g1-1 generator n=1 iWidth=1
tc g1-2 generator n=2 iWidth=1
tc g1-3 generator n=10 iWidth=1
tc g1-4 generator n=10 iWidth=1
tc g1-5 generator n=10 iWidth=1
tc g1-6 generator n=10 iWidth=1

group g2 35
limits wdecr=1 maxn=500 maxh=100000
include_group g1
tc g2-1 generator n=500 iWidth=1
tc g2-2 generator n=500 iWidth=1
tc g2-3 generator n=500 iWidth=1
tc g2-4 generator n=500 iWidth=1 genType=2
tc g2-5 generator n=500 iWidth=1 genType=2
tc g2-6 generator n=500 iWidth=1 genType=2

group g3 20
limits maxn=500 maxh=100000
include_group g2
tc g3-1 generator n=500
tc g3-2 generator n=500
tc g3-3 generator n=500 maxW=100
tc g3-4 generator n=500 genType=2
tc g3-5 generator n=500 genType=2
tc g3-6 generator n=500 genType=2

group large 26
include_group g3
tc 2
tc 3
tc large-1 generator n=100000
tc large-2 generator n=100000
tc large-3 generator n=100000 maxH=100
tc large-4 generator n=100000 maxH=1000000000
tc large-5 generator n=100000 maxH=1000000000
tc large-6 generator n=100000 genType=2
tc large-7 generator n=100000 genType=2
tc large-8 generator n=100000 genType=2 maxH=100
tc large-9 generator n=100000 genType=2 maxH=1000000000
tc large-10 generator n=100000 genType=2 maxH=1000000000

