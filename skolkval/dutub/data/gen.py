#!/usr/bin/env python3
import random
import sys

random.seed(sys.argv[-1])


def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False


n = int(cmdlinearg("n"))
prob = float(cmdlinearg("prob"))

alphabet = "abcdefghij"
A = len(alphabet)

costs = [random.randint(1, 10) for _ in range(A)]

print(n)
seen = set()
for i in range(n):
    s = 0
    o = ""
    while not s or o in seen:
        s = 0
        o = ""
        ar = [(True if random.uniform(0, 1) < prob else False) for _ in range(A)]
        for j in range(A):
            if ar[j]:
                s += costs[j]
                o += chr(97 + j)
    seen.add(o)
    s += random.randint(1, 10)
    print(s, o)
