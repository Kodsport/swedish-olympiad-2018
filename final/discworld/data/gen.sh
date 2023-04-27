#!/bin/sh

g++ -O2 joshua.cpp

./a.out 1 > secret/grupp1/1.in


g++ -O2 secret/compute_t.cpp

./a.out secret/grupp1/1.in > secret/grupp1/1.ans
