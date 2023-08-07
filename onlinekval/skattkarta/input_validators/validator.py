import re
import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

group = cmdlinearg("group")

#if group == "sample":
#    group = "g3"
#group = "g3"

INT = "(0|[1-9][0-9]*)?\\n"
MAP = "[<v>\\^AB]*\\n"

line = sys.stdin.readline()
assert re.match(INT, line)
R = int(line)
assert 1 <= R <= 100

line = sys.stdin.readline()
assert re.match(INT, line)
C = int(line)
assert 1 <= C <= 100

ac = 0
bc = 0
m = []
for i in range(R):
    line = sys.stdin.readline()
    assert re.match(MAP, line)
    s = line.strip()
    assert len(s) == C
    m.append(s)
    for c in s:
        if c == 'A': ac += 1
        if c == 'B': bc += 1

line = sys.stdin.readline()
assert len(line) == 0

assert ac == 1 and bc == 1

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
if group == "g1":
    poster = [
    "vv<<<<<",
    "vv>>v^^",
    "vv^<vA<",
    "vB^v<<^",
    "v>^v^<^",
    ">^<>>>^",
    ]
    assert ' '.join(m) == ' '.join(poster)
elif group == "g2":
    assert not loop
elif group == "g3":
    pass
elif group == "sample":
    pass
else:
    assert False

sys.exit(42)
