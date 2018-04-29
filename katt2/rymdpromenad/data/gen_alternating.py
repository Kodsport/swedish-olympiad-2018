#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 10,
    "a": -1,
    "b": -1,
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
    a = int(cmdlinearg("a"))
    b = int(cmdlinearg("b"))
    if a == -1:
        a = random.randint(1,n)
    if b == -1:
        b = random.randint(1,n)
    print(str(n)+" "+str(m))
    v = []
    for i in range(0,m):
        c = a
        if i%2 == 1:
            c = b
        v.append(c)
    print(" ".join([str(x) for x in v]))    

if __name__ == "__main__":
    main()

