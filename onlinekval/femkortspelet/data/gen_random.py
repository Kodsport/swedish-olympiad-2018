#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None
    return default

def solve(hand1, hand2):
    a = True
    acheat = False
    bcheat = False
    for i in range(5):
        if hand1[i][0] == hand2[i][0]:
            a = (hand1[i][1] > hand2[i][1])
        else:
            for j in range(i+1, 5):
                if     a and hand1[i][0] == hand2[j][0]:
                    bcheat = True
                if not a and hand2[i][0] == hand1[j][0]:
                    acheat = True
    return (a, acheat, bcheat)

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
mode = cmdlinearg('mode')
assert mode in ['samecol', 'nocheat', 'full']

while True:
    if mode == 'samecol':
        suite = random.choice('HSRK')
        cards = [(suite, num) for num in range(2, 15)]
    else:
        cards = [(suite, num) for suite in 'HSRK' for num in range(2, 15)]
    dealt = random.sample(cards, 10)
    hand1 = dealt[:5]
    hand2 = dealt[5:]
    _, acheat, bcheat = solve(hand1, hand2)
    if (acheat or bcheat) and mode == 'nocheat':
        continue
    break

for card in dealt:
    print(card[0], card[1])
