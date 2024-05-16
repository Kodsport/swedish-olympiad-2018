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
mask = cmdlinearg("mask", "1111")

a, b, c, d = (rnd.randint(50, 100) * int(mask[i]) for i in range(4))

print(a, b, c, d)
