#!/usr/bin/env python3
import sys

inp = [(int(line.split()[0]), line.split()[1]) for line in sys.stdin.readlines()[1:]]

n = len(inp)
for i in range(2**n):
    kat = ""
    tid = 0
    for k, (t, ka) in enumerate(inp):
        if ((i >> k) & 1) == 0:
            tid += t
            kat += ka
    nkat = len(set(list(kat)))
    if i == 0:
        maxkat = nkat
        mintid = tid
    elif nkat == maxkat:
        mintid = min(mintid, tid)
print(mintid)
