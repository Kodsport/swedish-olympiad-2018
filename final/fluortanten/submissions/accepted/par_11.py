import sys
a=[int(x) for x in sys.stdin.readlines()[1].split() if x!='0']
for i in range(len(a)-1):
    assert a[i] >= a[i+1]
print max(sum([x*(i+1) for i,x in enumerate(a)]),sum([x*(i+2) for i,x in enumerate(a)]))
