import sys
import random

random.seed(int(sys.argv[-1]))

case = int(sys.argv[1])

def edge_1s(L, R, swap):
    if swap:
        L, R = R, L

    B = 0.1
    A = L / (R / B + 1)

    if A < 0.1 or A > 1:
        B = 1
        A = L / (R / B + 1)
    return A, B

if case in [1, 2]:
    L = 30
    R = 60
    A, B = edge_1s(L, R, case % 2)
if case in [3, 4]:
    L = 30
    R = 20
    A, B = edge_1s(L, R, case % 2)
if case in [5, 6]:
    L = 100
    R = 100
    A, B = edge_1s(L, R, case % 2)
if case in [7, 8]:
    L = 60
    R = 30
    A, B = edge_1s(L, R, case % 2)
if case in [9, 10]:
    L = 2
    R = 10
    A, B = edge_1s(L, R, case % 2)

M = random.randint(30, 200)
S = random.randint(1, M)
G = S

print(M, S, G)
print(A, B)
print(L, R)
