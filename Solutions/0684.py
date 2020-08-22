from Euler.Solution import Solution
import Euler.Math as EM

# Very likely can be highly optimized
def s(n):
	#N = 1
	N = n    # Can I do this?
	while True:
		if EM.digitSum(N) == n: return N
		N += 1

# Does this hashing incur too much memory space?
known = {}
def S(k):
	retVal = 0

	for K in range(1, k + 1):
		if K not in known: known[K] = s(K)
		retVal += known[K]

	return retVal

def logic():
	# [NOTE] Not sure if I'm starting at the right value here
	a = 1
	b = 1
	#for n in range(90):
	for n in range(10):
		print(b, S(b))
		c = a + b
		a = b
		b = c

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
