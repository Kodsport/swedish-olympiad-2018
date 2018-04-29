import random
import sys
from collections import Counter
inp = raw_input

t = inp()
n, m = map(int, inp().split())
errors = Counter()
def score(g):
    c = 0
    for i in range(n):
        for j in range(m):
            if i < n - 2 and g[i][j] == g[i+1][j] == g[i+2][j]:
                c += 1
                errors[i, j, g[i][j]] += 1
                errors[i+1, j, g[i][j]] += 1
                errors[i+2, j, g[i][j]] += 1
            if j < m - 2 and g[i][j] == g[i][j+1] == g[i][j+2]:
                c += 1
                errors[i, j, g[i][j]] += 1
                errors[i, j+1, g[i][j]] += 1
                errors[i, j+2, g[i][j]] += 1
            if j < m - 2 and i < n-2:
                if g[i][j] == g[i+1][j+1] == g[i+2][j+2]:
                    c += 1
                    errors[i, j, g[i][j]] += 1
                    errors[i+1, j+1, g[i][j]] += 1
                    errors[i+2, j+2, g[i][j]] += 1
            if j >= 2 and i < n-2:
                if g[i][j] == g[i+1][j-1] == g[i+2][j-2]:
                    c += 1
                    errors[i, j, g[i][j]] += 1
                    errors[i+1, j-1, g[i][j]] += 1
                    errors[i+2, j-2, g[i][j]] += 1
    return c
                

cross = [int(x) for x in inp().split()]


def gensol(g):
    out = []
    for i, r in enumerate(g):
        cntx = len([v for v in r if v == 'x'])
        cnto = len([v for v in r if v == 'o'])
        xl = cross[i] - cntx
        ol = m - cross[i] - cnto
        nxt = []
        for j, v in enumerate(r):
            w = errors[(i, j, 'o')]
            b = errors[(i, j, 'x')]
            sm = w + b
            threshold = 0.5 if sm == 0 else float(b)/sm
            if v != '.': nxt.append(v)
            elif xl == 0:
                nxt.append('o')
                ol -= 1
            elif ol == 0:
                nxt.append('x')
                xl -= 1
            elif random.random() < threshold:
                nxt.append('o')
                ol -= 1
            else:
                nxt.append('x')
                xl -= 1
        out.append(nxt)
    return out

grid = [list(inp()) for _ in range(n)]

random.seed(37)

best, bestsc = None, n*m*4

itr = 10**6/(n*m)
for _ in range(itr):
    cpg = [[x for x in r] for r in grid]
    cpg = gensol(cpg)
    sc = score(cpg)
    if sc < bestsc:
        sys.stderr.write('new best score {}\n'.format(sc))
        bestsc = sc
        best = cpg
print('\n'.join(''.join(r) for r in best))

sys.stderr.write('score {}\n'.format(bestsc))


