#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh


use_solution ../kryssning_manyiters.py pypy
compile gen.py

mkdir -p sample/
python3 gen.py case=0 n=10 m=10 lo=0.5 hi=0.5 keep=0.1 bias=0 >sample/1.in

function ca {
	GNAME=grupp$(printf "%02d" $1)
	group $GNAME 10
	tc $1 gen case=$1 "${@:2}"
	echo "on_reject: break
range: 0 10
grader_flags: no_errors" >secret/$GNAME/testdata.yaml
}

ca 1 n=10 m=10 lo=0.4 hi=0.6 bias=0.9 keep=0.15
ca 2 n=7 m=500 lo=0.45 hi=0.55 bias=0.3 keep=0.3
ca 3 n=500 m=10 lo=0.2 hi=0.8 bias=0.7 keep=0.1
ca 4 n=100 m=100 lo=0.4 hi=0.6 bias=0.9 keep=0.2
ca 5 n=500 m=500 lo=0.35 hi=0.65 bias=0.3 keep=0.2
ca 6 n=500 m=500 lo=0.1 hi=0.7 bias=0.2 keep=0.3
ca 7 n=500 m=300 lo=0.3 hi=0.9 bias=0.8 keep=0.15
ca 8 n=500 m=500 lo=0.3 hi=0.6 bias=0 keep=0.5
ca 9 n=300 m=500 lo=0.35 hi=0.7 bias=0 keep=0.15
ca 10 n=500 m=500 lo=0.3 hi=0.7 bias=0 keep=0


