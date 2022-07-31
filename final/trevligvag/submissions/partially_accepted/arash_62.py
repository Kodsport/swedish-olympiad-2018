#! /usr/bin/python3
"""
Arash AC(61) trevligvag
"""
#pylint: disable=missing-docstring, invalid-name, not-callable
import sys
import collections
import itertools  # pylint: disable=unused-import
from pprint import pprint  # pylint: disable=unused-import

def main():
    stdin_lines = []
    for line in sys.stdin:
        if line.strip() != "":  # pylint: disable=not-callable
            stdin_lines.append(line.strip())  # pylint: disable=not-callable

    # Ignore parsing first line
    # parse step 2

    n, m = map(int, stdin_lines[0].split())
    assert n <= 1000 and m <= 2000
    def parse_line(line):
        a, b, w = line.split()  # pylint: disable=not-callable
        return (int(a), int(b), int(w))
    edges = [parse_line(line) for line in stdin_lines[1:]]
    print(solve(n, edges))


def solve(n, edges):
    edges.sort()
    ix_to_dist_to_weight = collections.defaultdict(
        lambda: collections.defaultdict(lambda: -1))
    ix_to_dist_to_weight[1][0] = 0
    for a, bws in itertools.groupby(edges, lambda x: x[0]):
        for _, b, dw in bws:
            for dist, w0 in ix_to_dist_to_weight[a].items():
                w1 = dw + w0
                ix_to_dist_to_weight[b][dist+1] = max(ix_to_dist_to_weight[b][dist+1], w1)
    candidates = list(w/dist for dist, w in ix_to_dist_to_weight[n].items() if dist > 0)
    return max(candidates) if candidates else "IMPOSSIBLE"

if __name__ == '__main__':
    main()
