import sys
a=[int(x) for x in sys.stdin.readlines()[1].split() if x!='0']
s=[]
for b in range(len(a)+1):
    s.append(sum([x*(i+(1 if i<b else 2)) for i,x in enumerate(a)]))
print max(s)
