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
n = int(cmdlinearg('n'))
dir = cmdlinearg('dir')
outputlim = int(cmdlinearg('outputlim', '100000'))
assert dir in ['left', 'right', 'rand']

def randname():
    le = random.randint(1, namelen)
    return ''.join(random.choice("asdfhuqwyeruyoirtdhfgzvbcmn") for _ in range(le))

res = []
def rec(level):
    if level == len(sizes):
        res.append(randname())
        return
    if level != 0:
        res.append('(')
        res.append(randname())
    args = sizes[level]
    args = random.randint(minarg, args) if random.uniform(0,1) < 0.5 else minarg
    for i in range(args):
        res.append(' ')
        rec(level+1)
    if level != 0:
        res.append(')')

def rec2(level):
    if level == n:
        res.append(randname())
        return
    d = dir
    if d == 'rand':
        d = random.choice(['left', 'right'])
    res.append('(')
    res.append(randname())
    if d == 'left':
        res.append(' ')
        rec2(level+1)
    rec(0)
    if d == 'right':
        res.append(' ')
        rec2(level+1)
    res.append(')')

rec2(0)
res = ''.join(res)
assert len(res) <= outputlim
print(res)
