#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

lim = 100000
small_lim = 80

def random_weights(gr, wmode):
    eds = []
    for i in range(n):
        for j in set(graph[i]):
            if i != j:
                assert i < j
                if wmode == 'uniform':
                    r = random.randrange(lim)
                elif wmode == 'prefer-small':
                    # larger (j - i) should give smaller r
                    r = -(j - i) * random.randint(1, small_lim)
                else:
                    assert False, "invalid weight parameter"
                eds.append((i,j,r))
    return eds

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
m = int(cmdlinearg('m'))
gmode = cmdlinearg('graph')
wmode = cmdlinearg('weights', '')
graph = [[] for _ in range(n)]
if gmode == 'random' or gmode == 'random-long' or gmode == 'random-very-long':
    for _ in range(m):
        if gmode == 'random':
            a = random.randrange(n)
            b = random.randrange(n)
            if a > b:
                a, b = b, a
        else:
            c = 0.3 if gmode == 'random-long' else 0.25
            le = 1 + random.randrange(int(n**c))
            a = random.randrange(n - le)
            b = a + le
            assert 0 <= a < b < n
        graph[a].append(b)
    for _ in range(10):
        graph[0].append(random.randrange(1, n // 5))
    for _ in range(10):
        graph[n - random.randrange(1, n // 5)].append(n-1)
    eds = random_weights(graph, wmode)
elif gmode == 'line' or gmode == 'line-perturbed':
    for i in range(n-1):
        graph[i].append(i+1)
    if gmode == 'line-perturbed':
        for _ in range(m):
            le = 1 + random.randrange(int(n**0.3))
            if n == 10:
                le = 3
            a = random.randrange(n - le)
            b = a + le
            assert 0 <= a < b < n
            graph[a].append(b)
    edg = int((n*10)**0.5)
    for _ in range(edg):
        graph[0].append(random.randrange(1, n // 5))
    for _ in range(edg):
        graph[n - random.randrange(1, n // 5)].append(n-1)
    eds = random_weights(graph, wmode)
else:
    assert False, "invalid graph parameter"

bias = [random.randrange(lim) for _ in range(n)]

for it in range(len(eds)):
    a, b, w = eds[it]
    eds[it] = (a, b, w + bias[b] - bias[a])

addevery = -min(x[2] for x in eds) + random.randint(1, lim)

random.shuffle(eds)
print(n, len(eds))
for (i, j, w) in eds:
    print(i+1, j+1, w + addevery)
