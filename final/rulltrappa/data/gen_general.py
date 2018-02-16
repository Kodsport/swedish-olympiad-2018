import sys
import random

random.seed(int(sys.argv[-1]))

M = random.randint(30, 200)
S = random.randint(1, M)
G = random.randint(S, M)
A = random.randint(1000, 10000) / 10000
B = random.randint(1000, 10000) / 10000
L = random.randint(0, 100)
R = random.randint(0, 100)

print(M, S, G)
print(A, B)
print(L, R)
