import sys
import random
from random import randrange, randint

def gen(n, iWidth=0, genType=1, maxW=10000000, maxH=100000):
    ws = []
    for i in range(n):
        if randint(1,5) == 1 and i != 0:
            ws.append(ws[randint(0,i-1)])
        else:
            ws.append(randint(1,maxW))

    ws.sort()
    ws.reverse()

    blocks = []

    if genType == 1: # uniform random
        for i in range(n):
            # reuse height one ninth of the time, else random
            if randrange(9) == 0 and i != 0:
                h = blocks[randrange(i)][1]
            else:
                h = randint(1, maxH)
            blocks.append((ws[i], h))

    if genType == 2: #increasing heights with small perturbations
        hs = []
        for i in range(n):
            # reuse height 5% of the time, else random
            if randrange(20) == 0 and i != 0:
                hs.append(hs[randrange(i)])
            else:
                hs.append(randint(1,maxH))

        hs.sort()

        for _ in range(int(n // 2)):
            a = randrange(n)
            b = a + int(50*random.uniform(-1,1)**4)
            if 0 <= b < n:
                hs[a],hs[b] = hs[b],hs[a]

        blocks = [(ws[i],hs[i]) for i in range(n)]

    if iWidth:
        for i in range(n):
            blocks[i] = (n-i, blocks[i][1])
    else:
        random.shuffle(blocks)

    print(n)
    for block in blocks:
        print(block[0], block[1])

argparts = [x.split("=") for x in sys.argv[1:-1] if "=" in x]
args = {key: int(value) for key, value in argparts}
random.seed(int(sys.argv[-1]))
gen(**args)
