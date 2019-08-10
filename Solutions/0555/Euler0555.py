def M(m, k, s, n):
	if n > m: return n - s
	else: return M(m, k, s, M(m, k, s, n + k))

# I'm finding that there seem to be some patterns associated with the cycle... Not sure exactly what though
def F(m, k, s):
	# Find the cycle
	# Cycle length seems to always be k - s
	# It also seems that as n decreases the cycle is still a subset of n0... hmmm...
	#    This actually doesn't seem to be true, look at the cycle of 20, 10, 1 - 9
	#    20, 10, 3 contains 18 which isn't in 20, 10, 1
	# Also it looks like cycle_k+1 = cycle_k shifted forward 2 places and truncated one in size
	# It also seems that in the cycle of m, s, k that the last cycle in the group is always len(1) and contains m - (s - 1)
	# The cycle set of m, s, k where cycle_end-1 = [cycle_end[0] + 2, cycle_end[0] + 1]
	# And the cycle set of m, s, k where cycle_end-2 = [cycle_end-2[0], cycle_end-2[0] + 1, cycle_end-2[0] + 2]
	# I don't know how they cycle changes after that though
	cycle = []
	start = None
	for n in range(max(m, k, s)):    # I think this only needs to go up to k tbh
		val = M(m, k, s, n)
		if val == start: break
		if start == None: start = val
		cycle.append(val)

	# Find fixed points within cycle
	fixedPoints = []
	for point in cycle:
		if cycle[point % len(cycle)] == point:
			fixedPoints.append(point)

	print("{}, {}, {} = {}".format(m, k, s, cycle))
	return set(fixedPoints)

def SF(m, k, s): return sum(F(m, k, s))

def S(p, m):
	total = 0
	for k in range(1, p + 1):
		for s in range(1, k):
			val = SF(m, k, s)
			total += val
	return total

print(S(20, 20))
print("Done")
