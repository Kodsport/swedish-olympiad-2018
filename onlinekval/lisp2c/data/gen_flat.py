#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
sizes = list(map(int, cmdlinearg('sizes').split(',')))
namelen = int(cmdlinearg('namelen', '10'))
minarg = int(cmdlinearg('minarg', '0'))
outputlim = int(cmdlinearg('outputlim', '100000'))

def randname():
    le = random.randint(1, namelen)
    return ''.join(random.choice("asdfhuqwyeruyoirtdhfgzvbcmn") for _ in range(le))

res = []
def rec(level):
    if level == len(sizes):
        res.append(randname())
        return
    res.append('(')
    res.append(randname())
    args = sizes[level]
    if level > 0:
        args = random.randint(minarg, args) if random.uniform(0,1) < 0.5 else minarg
    for i in range(args):
        res.append(' ')
        rec(level+1)
    res.append(')')

rec(0)
res = ''.join(res)
assert len(res) <= outputlim
print(res)
