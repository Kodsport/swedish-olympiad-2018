import re
import sys

INT_PAT = "(0|[1-9][0-9]*)"
INT = "^{0}\n$".format(INT_PAT)
INTS = "^{0} {0}\n$".format(INT_PAT)

def rl(pat=None):
    line = sys.stdin.readline()
    print repr(line)
    if pat is not None:
        assert re.match(pat, line), pat
    return line

line = rl(INT)
assert 0 <= int(line) <= 10
line = rl(INTS)
N, M = map(int, line.split())
assert 1 <= N <= 500
assert 1 <= M <= 500

line = rl("^({0} ){{{1}}}{0}\n$".format(INT_PAT, N-1))
parts = map(int, line.split(' '))
assert 0 <= min(parts) <= max(parts) <= M

for i in range(N):
    line = rl("^[ox.]{{{0}}}\n$".format(M))

line = rl()
assert len(line) == 0

sys.exit(42)
