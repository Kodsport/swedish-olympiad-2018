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


rnd.seed(int(cmdlinearg("seed", sys.argv[-1])))

n = int(cmdlinearg("n", 6))

WHITE = 0
BLACK = 1

board = [WHITE] * n

for _ in range(1000):
    # Choose which end to grab from
    start = rnd.randint(0, 1)

    if start == 0:
        pair = board[0:2]
        board = board[2:]
    else:
        pair = board[-2:]
        board = board[:-2]

    pair = [WHITE if i == BLACK else BLACK for i in pair]

    new_pos = rnd.randint(0, n - 2)
    board[new_pos:new_pos] = pair

print("".join("VS"[i] for i in board))
