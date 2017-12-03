import re
import sys

line = sys.stdin.readline()
R = int(line)
line = sys.stdin.readline()
C = int(line)
m = []
for i in range(R):
    line = sys.stdin.readline()
    s = line.strip()
    m.append(s)

x = 0
y = 0
seen = set()
loop = False
while m[x][y] not in ['A', 'B']:
    if (x, y) in seen:
        loop = True
        break
    seen.add((x, y))
    if m[x][y] == '<':
        y -= 1
    if m[x][y] == '>':
        y += 1
    if m[x][y] == '^':
        x -= 1
    if m[x][y] == 'v':
        x += 1

if loop:
    print("cykel")
elif m[x][y] == 'A':
    print("sushi")
else:
    print("samuraj")
