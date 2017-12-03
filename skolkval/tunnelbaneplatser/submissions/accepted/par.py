import sys
g = [int(x) for x in sys.stdin.readline().split()]
n = g[3]+g[2]
nled=g[2]
n+=(g[1]+1)/2
nled+=2*(g[1]%2)
g[0]-=nled
if(g[0]>0): n+=(g[0]+3)/4
print n
