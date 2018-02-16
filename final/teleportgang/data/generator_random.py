

#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "m": 20,
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
    print(str(n) + " " + str(m))
    [s,t] = random.sample(range(1,n+1),2)
    print(str(s) + " " + str(t))
    S = set()
    for i in range(0,m):
        while True:
            [u,v] = random.sample(range(1,n+1),2)
            uv = min(u,v)*n + max(u,v)
            if not (uv in S):
                S.add(uv)
                print(str(u) + " " + str(v))
                break
        

if __name__ == "__main__":
    main()






