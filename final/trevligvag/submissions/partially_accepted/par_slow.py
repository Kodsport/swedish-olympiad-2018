import sys
lines=sys.stdin.readlines()
N=int(lines[0].split()[0])
e=[[] for i in range(N)]
for line in lines[1:]:
    [a,b,w]=[int(x) for x in line.split()]
    e[a-1].append((b-1,w))
mx=[{} for i in range(N)]
mx[0][0]=0
for k in range(N):
    for (t,w) in e[k]:
        for (n,s) in mx[k].items():
            if (not n+1 in mx[t]) or (s+w>mx[t][n+1]):
                mx[t][n+1] = s+w
print "IMPOSSIBLE" if not mx[N-1] else max([float(s)/n for (n,s) in mx[N-1].items()])
