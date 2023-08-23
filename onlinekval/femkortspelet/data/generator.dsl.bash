#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution sl.py
compile gen_random.py

samplegroup
sample 1
sample 2
sample 3

group g1samecol 30
limits same=1
tc 1
for A in 1 2 3 4 5 6 7 8; do
	tc samecol-$A gen_random mode=samecol
done

group g2nocheat 30
limits nocheat=1
tc 1
for A in 1 2 3 4 5 6 7 8; do
	tc nocheat-$A gen_random mode=nocheat
done

group g3full 40
include_group g1samecol
include_group g2nocheat
tc 2
tc 3
for A in 1 2 3 4 5 6 7 8; do
	tc full-$A gen_random mode=full
done
