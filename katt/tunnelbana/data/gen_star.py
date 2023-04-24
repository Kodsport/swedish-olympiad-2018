#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 10,
    "k": 1,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    k = int(cmdlinearg("k"))
    print(str(n) + " " + str(m) + " " + str(k))

    edges = []
    for i in range(1,n):
        edges.append(str(1) + " " + str(i+1))
    random.shuffle(edges)
    for i in range(0,n-1):
        print(edges[i])

    for i in range(0,m):
        a = random.randint(1,n)
        b = random.randint(1,n)
        while a == b:
            b = random.randint(1,n)
        print(str(a) + " " + str(b))

if __name__ == "__main__":
    main()

