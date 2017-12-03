import random
import sys

R = 20
C = 20

G = [[random.choice(['<', 'v', '>', '^']) for _ in range(C)] for _ in range(R)]

r = 0
c = 0

seen = set()
assigned = []
while True:
    seen.add((r, c))
    while True:
        a = random.choice(['<', 'v', '>', '^'])
        nr = r
        nc = c
        if a == 'v':
            nr += 1
        if a == '<':
            nc -= 1
        if a == '>':
            nc += 1
        if a == '^':
            nr -= 1
        if nr < 0 or nr >= R or nc < 0 or nc >= C:
            continue
        if len(seen) <= 50 and (nr, nc) in seen:
            continue
        break
    G[r][c] = a
    if (nr, nc) in seen:
        if 'target' in sys.argv:
            G[nr][nc] = random.choice(['A', 'B'])
            assigned.append(G[nr][nc])
        break
    r = nr
    c = nc

if 'A' not in assigned:
    G[random.randint(0, R-1)][random.randint(0, C-1)] = 'A'
if 'B' not in assigned:
    G[random.randint(0, R-1)][random.randint(0, C-1)] = 'B'
print(R)
print(C)
for x in G:
    print(''.join(x))
