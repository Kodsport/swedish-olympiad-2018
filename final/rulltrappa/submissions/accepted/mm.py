#!/bin/python3

inp = input

M, S, G = map(int, inp().split())
A, B = map(float, inp().split())
L, R = map(int, inp().split())

tA = M/float(G) + L/A
tB = M/float(S) + R/B

print('latmask' if tA > tB else 'friskus')
