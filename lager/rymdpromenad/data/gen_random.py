#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 10,
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
    print(str(n)+" "+str(m))
    v = []
    for i in range(0,m):
        v.append(random.randint(1,n))
    print(" ".join([str(x) for x in v]))
    

if __name__ == "__main__":
    main()

