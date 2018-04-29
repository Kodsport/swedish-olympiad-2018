#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 10,
    "diff": 0,
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
    v = []
    for i in range(0,m):
        c = random.randint(0,diff)-diff//2
        if i%2 == 1:
            c += n//2
        while c < 0:
            c += n
        c %= n
        c += 1
        v.append(c)
    print(" ".join([str(x) for x in v]))
        
    

if __name__ == "__main__":
    main()

