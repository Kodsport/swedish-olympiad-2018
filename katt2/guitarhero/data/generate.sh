#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution sol_n_plus_q.cpp
compile generator.cpp # opt

samplegroup
sample 1

# n, m, q <= 50
group grupp1 25
tc small-1 generator 1 6 4 4 random random
tc small-2 generator 2 20 3 10 random random
tc small-3 generator 3 50 2 50 often_equal 0.6 random
tc small-4 generator 4 48 1 45 often_equal 1.0 random
tc small-5 generator 5 50 50 50 random random
tc small-6 generator 6 50 5 50 bidirectional 0.05 random
tc small-7 generator 7 50 5 50 unidirectional 0.02 random
tc small-8 generator 8 50 3 50 unidirectional 0.4 random
tc small-9 generator 9 29 3 25 bidirectional 0.2 random
tc small-10 generator 10 50 2 50 random narrow 5
tc small-11 generator 11 50 1 50 random random
tc small-12 generator 12 50 49 50 unidirectional 0.0 wide
tc small-13 generator 13 50 50 50 unidirectional 0.0 random
tc small-14 generator 14 25 3 10 random wide

# n, m, q <= 5000
group grupp2 25
include_group grupp1
tc medium-15 generator 15 5000 4999 5000 unidirectional 0.0 wide
tc medium-16 generator 16 5000 5000 5000 unidirectional 0.0 wide
tc medium-17 generator 17 5000 5000 5000 random random
tc medium-18 generator 18 5000 5 5000 random random
tc medium-19 generator 19 5000 7 5000 random random
tc medium-20 generator 20 5000 3 5000 random random
tc medium-21 generator 21 5000 4 5000 often_equal 0.95 random
tc medium-22 generator 22 5000 1 5000 often_equal 1.0 random
tc medium-23 generator 23 5000 67 5000 bidirectional 0.07 random
tc medium-24 generator 24 5000 450 5000 bidirectional 0.001 random
tc medium-25 generator 25 5000 607 5000 unidirectional 0.0007 random
tc medium-26 generator 26 4999 1582 4999 unidirectional 0.0004 wide
tc medium-27 generator 27 5000 4 5000 random narrow 80
tc medium-28 generator 28 5000 1 5000 random narrow 2

# m <= 5
group grupp3 25
tc narrow-29 generator 29 100000 5 100000 random random
tc narrow-30 generator 30 100000 5 100000 often_equal 0.99 random
tc narrow-31 generator 31 100000 4 100000 unidirectional 0.01 random
tc narrow-32 generator 32 100000 3 100000 bidirectional 0.001 narrow 10
tc narrow-33 generator 33 99997 5 59283 often_equal 0.2 random
tc narrow-34 generator 34 100000 1 100000 random random
tc narrow-35 generator 35 100000 1 100000 unidirectional 0.2 narrow 200
tc narrow-36 generator 36 1382 2 100000 random random
tc narrow-37 generator 37 100000 3 100000 random random
tc narrow-38 generator 38 100000 4 100000 random random
tc narrow-39 generator 39 8943 5 13843 random wide
tc narrow-40 generator 40 100000 5 100000 often_equal 0.9998 wide

# n, m, q <= 10^5
group grupp4 25
include_group grupp2
include_group grupp3
tc large-41 generator 41 100000 100000 100000 random random
tc large-42 generator 42 98582 8 100000 random random
tc large-43 generator 43 99192 6 99999 random wide
tc large-44 generator 44 99999 7 100000 random random
tc large-45 generator 45 99999 5 100000 often_equal 0.99 random
tc large-46 generator 46 99859 6 99493 often_equal 0.995 wide
tc large-47 generator 47 99998 108 99783 unidirectional 0.01 random
tc large-48 generator 48 99990 38029 100000 unidirectional 0.00001 random
tc large-49 generator 49 100000 82950 100000 unidirectional 0.00001 wide
tc large-50 generator 50 100000 57182 100000 unidirectional 0.00004 random
tc large-51 generator 51 100000 100000 100000 unidirectional 0.000001 wide
tc large-52 generator 52 100000 98042 100000 bidirectional 0.00001 narrow 50
tc large-53 generator 53 100000 128 100000 bidirectional 0.008 random
tc large-54 generator 54 99999 371 100000 bidirectional 0.012 random
tc large-55 generator 55 100000 15 100000 bidirectional 0.05 narrow 200
tc large-56 generator 56 100000 1 100000 often_equal 0.7 narrow 500
tc large-57 generator 57 100000 99999 100000 unidirectional 0.0 wide
tc large-58 generator 58 100000 100000 100000 unidirectional 0.0 wide
tc large-59 generator 59 1 100000 100000 random random
tc large-60 generator 60 100000 100000 1 random random
tc large-61 generator 61 100000 2058 100000 unidirectional 0.0008 random
tc large-62 generator 62 100000 10 100000 often_equal 0.9999 wide

cleanup_programs
