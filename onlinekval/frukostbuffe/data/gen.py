import random
import sys

n, a_min, a_max = map(int, sys.argv[1:])

a = [random.randrange(a_min, a_max + 1) for _ in range(n)]


print(n)
print(' '.join(map(str, a)));
