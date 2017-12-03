import sys
n=int(sys.stdin.readline())
hlist = [int(x) for x in sys.stdin.readline().split()]
now=down=0
for h in reversed(hlist):
    if h>=now+down:
        now=h
        down=0
    else:
        down=(now+down)-h
        now=h+down
print down



