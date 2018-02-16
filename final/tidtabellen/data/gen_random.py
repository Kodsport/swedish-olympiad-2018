#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

day = 60*60*24

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
nanswers = int(cmdlinearg('n'))
m = eval(cmdlinearg('m'))
sym = eval(cmdlinearg('sym'))
extra = int(cmdlinearg('extra', 0))
mode = cmdlinearg('mode', '')
error = cmdlinearg('error', '')

lo = 0
size = day
if mode == 'nowrap':
    lo = random.randrange(0, day // 4)
    size = random.randrange(day // 4, 3 * day // 4)
    size = size // sym * sym

assert size % sym == 0
assert m % sym == 0

times = []
part = size // sym
for _ in range(m // sym):
    x = random.randrange(0, part)
    for k in range(sym):
        times.append(x + k * part)
if extra > 0:
    for _ in range(extra):
        times.append(random.randrange(0, size))
if extra < 0:
    rem = random.sample(times, -extra)
    times = list(set(times) - set(rem))

while extra > 0 and extra + m == nanswers and len(set(times)) < nanswers:
    times.append(random.randrange(0, size))


times = [x + lo for x in set(times)]
times.sort()

while True:
    query = random.randrange(0, size)
    answers = []
    has_first = (error != 'skipfirst')
    for t in times:
        if t >= query:
            if has_first:
                answers.append(t - query)
            else:
                has_first = True
    if len(answers) < nanswers and mode == 'nowrap':
        # answers wrapped around (they still might for some other solution, but
        # it's unlikely, and the input validator asserts that it doesn't happen)
        continue
    if not has_first:
        continue
    it = 0
    if error == 'skipaday':
        if len(answers) >= nanswers:
            continue
        it = 1
    while len(answers) < nanswers:
        it += 1
        for t in times:
            answers.append(it * day + t - query)
    del answers[nanswers:]
    break

if error == 'wrong' or error == 'wrong-small':
    lim = 10**9 if error == 'wrong' else day
    answers = random.sample(range(0, lim), nanswers)
    answers.sort()

assert answers[-1] <= 10**9

print(nanswers, len(times))
print(*answers)
for t in times:
    h = t // (60*60)
    t -= 60*60*h
    m = t // 60
    t -= 60*m
    s = t
    print('{:02}:{:02}:{:02}'.format(h,m,s))
