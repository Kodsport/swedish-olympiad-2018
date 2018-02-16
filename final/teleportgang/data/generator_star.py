

#!/usr/bin/python3

import sys
import random

default = {
    "n": 10,
    "star": -1,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    star = n
    if int(cmdlinearg("star")) != -1:
        star = int(cmdlinearg("star"))
    print(str(n) + " " + str(star-1))
    print(str(n) + " 1")
    for i in range(1,star):
        print(str(1) + " " + str(i+1))

if __name__ == "__main__":
    main()






