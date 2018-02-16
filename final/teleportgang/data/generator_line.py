

#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "s": -1,
    "t": -1,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    print(str(n) + " " + str(n-1))
    [s,t] = random.sample(range(1,n+1),2)
    if int(cmdlinearg("s")) != -1 and int(cmdlinearg("t")) != -1:
        s = int(cmdlinearg("s"))
        t = int(cmdlinearg("t"))
    print(str(s) + " " + str(t))
    for i in range(n-1):
        print(str(i+1) + " " + str(i+2))
        

if __name__ == "__main__":
    main()






