#!/bin/sh

g++ -O2 js.cpp

./a.out 1 > secret/grupp1/1.in
./a.out 2 > secret/grupp2/2.in
./a.out 3 > secret/grupp3/3.in
./a.out 4 > secret/grupp4/4.in
./a.out 5 > secret/grupp5/5.in

g++ -O2 secret/compute_t.cpp

./a.out secret/grupp1/1.in > secret/grupp1/1.ans
./a.out secret/grupp2/2.in > secret/grupp2/2.ans
./a.out secret/grupp3/3.in > secret/grupp3/3.ans
./a.out secret/grupp4/4.in > secret/grupp4/4.ans
./a.out secret/grupp5/5.in > secret/grupp5/5.ans
