#!/usr/bin/env python3
import sys

line = input()
assert 2 <= len(line) <= 10**5

for ch in line:
    assert ord('a') <= ord(ch) <= ord('l')

line = sys.stdin.readline()
assert len(line) == 0
exit(42)
