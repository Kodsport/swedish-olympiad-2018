#Wrong: Bjorn not tested at place number n
import sys
a=[int(x) for x in sys.stdin.readlines()[1].split() if x!='0']
s=[sum([x*(i+2) for i,x in enumerate(a)])]
for an in a: s.append(s[-1]-an)
print(max(s[:-1]))
