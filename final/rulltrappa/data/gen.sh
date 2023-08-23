#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution js.cpp
compile gen_lr.py
compile gen_sg.py
compile gen_general.py

samplegroup
sample 1
sample 2
sample 3

group grupp1 40
limits lr0=1
tc 1-01-lr_1 gen_lr 1
tc 1-02-lr_2 gen_lr 2
tc 1-03-lr_3 gen_lr 3
tc 1-04-lr_4 gen_lr 4
tc 1-05-lr_5 gen_lr 5

group grupp2 40
limits sgeq=1
tc 2-01-sg_1 gen_sg 1
tc 2-02-sg_2 gen_sg 2
tc 2-03-sg_3 gen_sg 3
tc 2-04-sg_4 gen_sg 4
tc 2-05-sg_5 gen_sg 5
tc 2-06-sg_6 gen_sg 6
tc 2-07-sg_7 gen_sg 7
tc 2-08-sg_8 gen_sg 8
tc 2-09-sg_9 gen_sg 9
tc 2-10-sg_10 gen_sg 10

group grupp3 20
include_group grupp1
include_group grupp2
include_group sample
tc 3-01-lr_1 gen_lr 1
tc 3-02-lr_2 gen_lr 2
tc 3-03-lr_3 gen_lr 3
tc 3-04-lr_4 gen_lr 4
tc 3-05-lr_5 gen_lr 5

tc 3-01-sg_1 gen_sg 1
tc 3-02-sg_2 gen_sg 2
tc 3-03-sg_3 gen_sg 3
tc 3-04-sg_4 gen_sg 4
tc 3-05-sg_5 gen_sg 5
tc 3-06-sg_6 gen_sg 6
tc 3-07-sg_7 gen_sg 7
tc 3-08-sg_8 gen_sg 8
tc 3-09-sg_9 gen_sg 9
tc 3-10-sg_10 gen_sg 10

tc 3-01-rand gen_general
tc 3-02-rand gen_general
tc 3-03-rand gen_general
tc 3-04-rand gen_general
