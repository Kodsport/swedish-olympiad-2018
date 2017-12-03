#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None
    return default

random.seed(int(cmdlinearg("seed", sys.argv[-1])))
n = int(cmdlinearg("n"))
minv = int(cmdlinearg("minv"))
maxv = int(cmdlinearg("maxv"))
padl = int(cmdlinearg("padl", "0"))
padr = int(cmdlinearg("padr", "0"))

vals = [0] * padl + [random.randint(minv, maxv) for _ in range(n)] + [0] * padr

print(len(vals))
print(*vals)
