import random
import sys
random.seed(sys.argv[-1])

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

n = int(cmdlinearg('n'))
r = int(cmdlinearg('r'))

assert n >= 2
ar = [0] * n

for _ in range(r):
    if random.randrange(2) != 0:
        ar = ar[::-1]
    part = ar[-2:]
    part[0] = 1-part[0]
    part[1] = 1-part[1]
    ar = ar[:-2]
    ind = random.randrange(len(ar)+1)
    ar[ind:ind] = part

print(''.join('VS'[x] for x in ar))
