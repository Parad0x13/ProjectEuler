from Euler.Solution import Solution
import Euler.Math as EM

def orderedDigits(N):
	count = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0}

	while N > 0:
		n = N % 10
		count[n] += 1
		N //= 10

	retVal = 0
	for current in range(1, 10):    # We can skip zero
		for c in range(count[current]):
			retVal *= 10
			retVal += current
	return retVal

def logic():
	S = 6    # How many digits to run up to
	total = 0
	for n in range(10 ** S):
		total += orderedDigits(n)
	print(total)


solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
