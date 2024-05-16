#!/usr/bin/env python3

# För att generera en uppgift gör vi följande:
# - 1. Välj ett kvadrat tal större än low och kalla det för a
# - 2. Låt nästa kvadrat tal heta b.
# - 3. Välj två tal mellan a och b. a,b \in [a, b)
# - 4. Kolla om a,b ger ett svar
# - 5a. Om inte öka a med 1
# - 5b. Om det stämmer skriv ut och exit
# - 6. gå till 4

import sys
import random as rnd
from math import isqrt

from solve import allowed


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default


lo, hi = int(cmdlinearg("lo", 10**12)), int(cmdlinearg("hi", 10**12))

rnd.seed(cmdlinearg("seed", sys.argv[-1]))
if cmdlinearg("eq", "no") == "yes":
    lo = hi = rnd.randint(lo, hi)
    print(lo, hi)
    exit()

lo_bound: int = isqrt(lo)
hi_bound: int = isqrt(hi)

relo: int = rnd.randint(lo_bound, hi_bound) ** 2
if relo < lo:
    relo = lo

rehi: int = (isqrt(relo) + 1) ** 2 - 1
if rehi > hi:
    rehi = hi

while not allowed(relo, rehi):
    relo += 1
    if relo > rehi:
        print("Error: couldn't find any pair in range!")

print(relo, rehi)
