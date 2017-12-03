#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution sl.cpp
compile gen_flat.py
compile gen_nested.py

samplegroup
sample 1
sample 2
sample 3

# ingen parameter i indatan är ett funktionsanrop.
group flat 16
tc flat-01 gen_flat sizes=0
tc flat-02 gen_flat sizes=1
tc flat-03 gen_flat sizes=10
tc flat-04 gen_flat sizes=1000
tc flat-05 gen_flat sizes=40000 namelen=1

# anropen är nästlade högst två nivåer: \texttt{(a (b) (c))} kan förekomma, men inte \texttt{(a (b (c)))}.
group semiflat 27
include_group flat
tc semiflat-01 gen_flat sizes=1,0
tc semiflat-02 gen_flat sizes=10,100
tc semiflat-03 gen_flat sizes=100,0
tc semiflat-04 gen_flat sizes=1000,140 namelen=1
tc semiflat-05 gen_flat sizes=7,10000 namelen=1

# alla anrop har minst en parameter, och att alla variabler och funktionsnamn består av enbart en bokstav.
group simple 15
tc simple-01 gen_flat sizes=7,10000 namelen=1 minarg=1
tc simple-02 gen_flat sizes=1000,140 namelen=1 minarg=1
tc simple-03 gen_flat sizes=1 namelen=1
tc simple-04 gen_flat sizes=5,5,5,5,5,5,5,5,5,5,5,5 namelen=1 minarg=1 seed=15
tc simple-05 gen_nested sizes=3,2,3,7,7,7,7 n=100 dir=rand namelen=1 minarg=1

# indatan är högst $100$ tecken lång.
group small 28
tc small-01 gen_flat sizes=0 namelen=1 outputlim=100
tc small-02 gen_flat sizes=1 namelen=2 outputlim=100
tc small-03 gen_flat sizes=10 namelen=3 outputlim=100
tc small-04 gen_flat sizes=10 namelen=3 outputlim=100
tc small-05 gen_flat sizes=3,3,3,3 namelen=2 outputlim=100 seed=15
tc small-06 gen_nested sizes=3,1 n=9 dir=left namelen=2 outputlim=100 seed=123
tc small-07 gen_nested sizes=3,1 n=9 dir=rand namelen=2 outputlim=100 seed=127

# inga speciella begränsningar.
group large 14
include_group semiflat
include_group simple
include_group small
tc large-01 gen_flat sizes=6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6 namelen=2 seed=15
tc large-02 gen_nested sizes=3,2,3,7,7,7,7 n=100 dir=rand namelen=2 minarg=1
tc large-03 gen_flat sizes=1 namelen=100000 seed=22

generate_grader
cleanup_programs

