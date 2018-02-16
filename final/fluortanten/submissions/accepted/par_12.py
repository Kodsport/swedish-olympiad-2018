import sys
a=[int(x) for x in sys.stdin.readlines()[1].split() if x!='0']
for i in range(len(a)-1):
    assert a[i] <= a[i+1]
s=sum([x*(i+2) for i,x in enumerate(a)])
for an in a: 
   if an>0: break
   s-=an
print s
