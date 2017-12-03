#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
    "max": 1000000000,
    "minage": 1,
    "maxage": 1000000000,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

random.seed(int(sys.argv[-1]))
n = int(cmdlinearg("n"))
maxd = int(cmdlinearg("max"))
minage = int(cmdlinearg("minage"))
maxage = int(cmdlinearg("maxage"))
print(n)

births = random.sample(range(0, maxd), n)
for birth in births:
    age = random.randint(minage, maxage)
    death = min(10**9, birth + age)
    if minage == maxage:
        assert death == birth + age
    print(birth, death)
