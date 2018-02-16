import sys
import random

random.seed(int(sys.argv[-1]))

case = int(sys.argv[1])
L = 0
R = 0
if case == 1:
    M = 200
    S = 100
    G = 200
if case == 2:
    M = 200
    S = 1
    G = 2
if case == 3:
    M = 200
    S = 1
    G = 3
if case == 4:
    M = 30
    S = 15
    G = 30
if case == 5:
    M = 100
    S = 33
    G = 50

A = random.randint(1000, 10000) / 10000
B = random.randint(1000, 10000) / 10000

print(M, S, G)
print(A, B)
print(L, R)
