def M(m, k, s, n):
	if n > m: return n - s
	else: return M(m, k, s, M(m, k, s, n + k))

def findCycle(m, k, s):
	cycle = []
	start = None
	for n in range(max(m, k, s)):    # I think this only needs to go up to k tbh
		val = M(m, k, s, n)
		if val == start: break
		if start == None: start = val
		cycle.append(val)
	return cycle

def findFixedPoints(cycle):
	fixedPoints = []
	for point in cycle:
		if cycle[point % len(cycle)] == point: fixedPoints.append(points)
	# Possible optimization here, not sure why it works...
	# Can we assume that if the first in the cycle works then they will all work?
	# Seems to be the case, not sure why
	#if cycle[cycle[0] % len(cycle)] == cycle[0]: fixedPoints = cycle
	return fixedPoints

def F(m, k, s):
	cycle = findCycle(m, k, s)
	fixedPoints = findFixedPoints(cycle)
	print("{}, {}, {} = {}: {}, {}, {}".format(m, k, s, cycle, min(cycle), max(cycle), cycle.index(m - s + 1)))
	return set(fixedPoints)

def SF(m, k, s): return sum(F(m, k, s))

def S(p, m):
	total = 0
	for k in range(1, p + 1): total += SF(m, k, s)
	return total

print(S(10, 10))
print("Done")

print("\nCurrently Testing Hypothesis")

m = 10
k = m
s = k - 1
p = m

# OBSERVATIONS
cycle_len = k - s
cycle_min = m - s + 1
cycle_max = m - 2*s + k    # min(cycle) + len(cycle) - 1 = m - 2s + k, [NOTE] Can bitshift s, test this

# The core cycle can be precalculated and correlated with an offset index table for every cycle iterating through s
# Offsets consist of two sections: normal and weird in that order
offsets_len = cycle_len
offsetsNormal_max = int(m / 2)
offsetsWeird_len = m - offsetsNormal_max
offsetsNormal_len = offsets_len - offsetsWeird_len
offsetsNormal_min = offsetsNormal_max - offsetsNormal_len
offsetsNormal = list(range(offsetsNormal_min + 1, offsetsNormal_max + 1))    # [TODO] Calculate once and reuse

# HUGE REALIZATION!!! The weird values from within each k cycle match the offsets in each of the k cycles!!!

# Discover weirds
weirds = []
for k in range(2, p + 1):
	cycle = findCycle(m, k, 1)
	index = cycle.index(min(cycle))
	if index == offsetsWeird_len: break
	weirds.append(index)
print(weirds)

for minimalAnchor in range(m, 1, -1): print(minimalAnchor)    # This is the proper minimum anchor calculation

# [LEFT OFF] Working on extrapolating future values out of cycle_s=1 for each value of k
# Then I need to find if there's a way to extract previous k cycles out of cycle_k=m_s=1
# This way I should only need to calculate the 'weird' values and then cycle_k=m_s=1

"""
total = 0
for k in range(2, p + 1):
	cycle = findCycle(m, k, 1)
	index = cycle.index(min(cycle))

	# Once this is true we are now processing offsetsNormal values
	if index == offsetsWeird_len: pass

	for s in range(1, k):
		cycle = findCycle(m, k, s)
		fixedPoints = findFixedPoints(cycle)
		print("{}, {}, {} = {}: {}, {}, {}".format(m, k, s, cycle, min(cycle), max(cycle), cycle.index(m - s + 1)))
		total += sum(fixedPoints)
print()
print(total)
"""

print("Done Testing")
