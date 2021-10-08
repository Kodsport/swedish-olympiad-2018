#!/usr/bin/python3

import sys
import random

default = {
    "n": 20,
    "k": 2,
    "perturb": 0,
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
    perturb = int(cmdlinearg("perturb"))
    res = ""
    alfa = "abcdefghijkl"

    diff = n-2*k
    for i in range(0,k):
        res += alfa[i]
    for i in range(0,diff):
        res += 'a'
    for i in range(0,k):
        res += alfa[i]
    
    L = list(res)
    for i in range(0,perturb):
        [x,y] = random.sample(range(0,n),2)
        temp = L[x]
        L[x] = L[y]
        L[y] = temp
        
    res = ''.join(L)
    print(res)

if __name__ == "__main__":
    main()

