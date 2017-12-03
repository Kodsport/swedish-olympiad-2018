#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution sl.py
compile gen_random.py

samplegroup
sample 1
sample 2
sample 3

group samecol 30
for A in 1 2 3 4 5 6 7 8; do
	tc samecol-$A gen_random mode=samecol
done

group nocheat 30
include_group samecol
for A in 1 2 3 4 5 6 7 8; do
	tc nocheat-$A gen_random mode=nocheat
done

group full 40
include_group nocheat
for A in 1 2 3 4 5 6 7 8; do
	tc full-$A gen_random mode=full
done

generate_grader
cleanup_programs
