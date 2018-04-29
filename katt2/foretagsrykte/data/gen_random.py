#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))
alo = int(cmdlinearg('lo'))
ahi = int(cmdlinearg('hi'))
assert alo <= ahi
dist = cmdlinearg('dist', 'uniform')
if dist == 'uniform':
    li = [random.randint(alo, ahi) for _ in range(n)]
elif dist == 'exp':
    li = [min(ahi, max(alo, 2 ** random.randint(int(math.log2(alo)), int(math.log2(ahi))))) for _ in range(n)]
elif dist == 'same':
    val = ahi
    li = [val for _ in range(n)]
else:
    assert False, "unknown dist value"
print(n, k)
print(*li)
