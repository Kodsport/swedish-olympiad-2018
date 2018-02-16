import re
import sys

#group = sys.argv[1]

#if group == "sample":
#    group = "g3"
#group = "g3"

INT = "(0|[1-9][0-9]*)?"
INTS = INT + " " + INT + "\\n"

line = sys.stdin.readline()
assert re.match(INTS, line)
N, M = map(int, line.split())
assert 1 <= N <= 1000000
assert 0 <= M <= 3000

line = sys.stdin.readline()
parts = line.split(' ')
last = -1
for x in parts:
    assert re.match(INT, x)
    x = int(x)
    assert x > last
    assert 0 <= x <= 10**9
    last = x

last = -1
for i in range(M):
    line = sys.stdin.readline()
    assert re.match('([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]\\n', line)
    parts = list(map(int, line.split(':')))
    t = parts[0] * 60 * 60 + parts[1] * 60 + parts[2]
    assert t > last
    last = t

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
