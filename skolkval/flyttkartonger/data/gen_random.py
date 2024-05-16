#!/usr/bin/env python3

import sys
import random as rnd


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default


rnd.seed(cmdlinearg("seed", sys.argv[-1]))

lo = int(cmdlinearg("lo", 3))
hi = int(cmdlinearg("hi", 20))
n = int(cmdlinearg("n", rnd.randint(lo, hi)))

max_ai = int(cmdlinearg("max_ai", 3000))
blocks = [rnd.randint(1, max_ai) for _ in range(n)]

print(n)
print(*blocks)
