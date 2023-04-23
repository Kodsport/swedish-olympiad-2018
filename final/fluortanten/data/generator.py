import sys
import random

def getnum(a):
    k = 0
    while k==0:
        k = random.randrange(-a, a+1)
    return k

def gen(n, a = 1000, s=0):
    v = [getnum(a) for _ in range(n)]
    v[random.randrange(n)] = 0

    if s == 1:
        v.sort()
    if s == -1:
        v.sort(reverse=True)

    print(n)
    print(" ".join([str(x) for x in v]))

argparts = [x.split("=") for x in sys.argv[1:-1] if "=" in x]
args = {key: int(value) for key, value in argparts}
random.seed(int(sys.argv[-1]))
gen(**args)
