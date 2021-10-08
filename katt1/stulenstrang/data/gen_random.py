#!/usr/bin/python3

import sys
import random

default = {
    "n": 20,
    "k": 2,
    "impossible": 0,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    k = int(cmdlinearg("k"))
    impossible = int(cmdlinearg("impossible"))
    res = ""
    alfa = "abcdefghijkl"
    for i in range(0,k):
        res += alfa[i]
    for i in range(0,n//2-k):
        res += alfa[random.randint(0,k-1)]
    res += res
    if n%2 == 1:
        res += alfa[random.randint(0,k-1)]
    if impossible == 1:
        if res[0] == 'a':
            res = alfa[random.randint(1,k-1)]+res[1:]
        else:
            res = 'a'+res[1:]
    L = list(res)
    random.shuffle(L)
    res = ''.join(L)
    print(res) 

if __name__ == "__main__":
    main()

