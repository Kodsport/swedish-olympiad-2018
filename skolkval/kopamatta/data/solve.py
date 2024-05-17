#!/usr/bin/env pypy3

from math import isqrt


def allowed(lo: int, hi: int):
    a: int = isqrt(lo)

    if lo > a * a:
        a += 1

    if lo <= a * a <= hi:
        if lo <= (a + 1) * (a + 1) <= hi:
            print(f"Multiple perfect squares: {a} and {a+1}")
            return False
        # print(f"{a} {a}")
        return True

    while True:
        a -= 1
        b = hi // a

        if lo <= a * b <= hi:
            if lo <= (a) * (b - 1) <= hi or lo <= (a - 1) * (b) <= hi:
                print(f"Multiple rectangles around {a} {b}")
                return False
            # print(f"{a} {b}")
            return True


if __name__ == "__main__":
    lo, hi = map(int, input().split())
    allowed(lo, hi)
