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

case = int(cmdlinearg('case'))
n = int(cmdlinearg('n'))
m = int(cmdlinearg('m'))
ratlo = float(cmdlinearg('lo'))
rathi = float(cmdlinearg('hi'))
keep = float(cmdlinearg('keep'))
bias = float(cmdlinearg('bias'))

random.seed(case)

print(case)
print(n, m)

grid = [[None] * m for _ in range(n)]
for i in range(n):
    prob = random.uniform(ratlo, rathi)
    for j in range(m):
        badcross = 0
        badring = 0
        if j >= 2 and grid[i][j-1] == grid[i][j-2] == 'x':
            badcross += 1
        if j >= 2 and grid[i][j-1] == grid[i][j-2] == 'o':
            badring += 1
        if i >= 2 and grid[i-1][j] == grid[i-2][j] == 'x':
            badcross += 1
        if i >= 2 and grid[i-1][j] == grid[i-2][j] == 'o':
            badring += 1
        if badring != badcross and random.random() < bias:
            if badring > badcross:
                grid[i][j] = 'x'
            else:
                grid[i][j] = 'o'
        else:
            if random.random() < prob:
                grid[i][j] = 'x'
            else:
                grid[i][j] = 'o'

crosses = [0] * n
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'x':
            crosses[i] += 1
        else:
            assert grid[i][j] == 'o'
        if random.random() >= keep:
            grid[i][j] = '.'

print(*crosses)
for i in range(n):
    print(''.join(grid[i]))
