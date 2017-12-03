#!/usr/bin/env python3
import heapq

n = int(input())
birth_to_id = {}
result = [0] * n

# Birth event: (birth_year, -1)
# Death event: (death_year, birth_year)
events = []

for i in range(n):
    birth, death = map(int, input().strip().split())
    birth_to_id[birth] = i
    events.append((birth, -1))
    events.append((death, birth))

# Sort events by year (birth_year for birth events, death_year for
# death events).
events = sorted(events)

# Heap holding the birth years of all people currently alive
alive = []

# Set of the birth years of all dead people so far.
dead = set()

# Let's simulate! We only need to do work for the years when something happens.
last_year = -1
for a, b in events:
    # If there is at least one person alive, update the number of speeches made
    # by the oldest person.
    if len(alive) > 0:
        result[birth_to_id[alive[0]]] += a - last_year
    if b == -1: # Birth event - add to alive heap.
        heapq.heappush(alive, a)
    else: # Death event - add to dead set.
        dead.add(b)

        # We only care about the oldest person at any time, so we only need to
        # make sure that front of the heap is still alive.
        while len(alive) > 0 and alive[0] in dead:
            heapq.heappop(alive)

    last_year = a

# Print results.
print("\n".join(map(str, result)))
