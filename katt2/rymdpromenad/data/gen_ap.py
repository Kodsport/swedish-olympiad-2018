#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 10,
    "diff": 1,
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
    diff = int(cmdlinearg("diff"))
    print(str(n)+" "+str(m))
    start = 0
    v = []
    for i in range(0,m):
        v.append(start+1)
        start += diff
        while start < 0:
            start += n
        start %= n
    print(" ".join([str(x) for x in v]))
    

if __name__ == "__main__":
    main()

