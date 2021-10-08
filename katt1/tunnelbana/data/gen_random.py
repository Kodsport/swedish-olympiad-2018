#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 10,
    "k": 1,
    "height": 0,
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
    height = int(cmdlinearg("height"))
    print(str(n) + " " + str(m) + " " + str(k))

    nodes = list(range(1,n+1))
    random.shuffle(nodes)
    edges = []
    for i in range(1,n):
        if i <= height:
            edges.append(str(nodes[i-1]) + " " + str(nodes[i]))
        else:
            j = random.randint(0,i-1)
            edges.append(str(nodes[j]) + " " + str(nodes[i]))
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

