"""
Wow... this one made my head swim at first!
"""

from Euler.Solution import Solution
import Euler.Math as EM
import math

def logic():
	# Correct sequence will start off like: [1, 2, -5, 4, 17, -10, -17, 8, -47, 34]
	N = 10 ** 1

	values = {}
	values[1] = 1

	#for n in range(1, N):
	for n in range(1, int(N / 2) + 1):    # I think this is mathematically 'correct-ish' I just need to find a way to stop it exactly on the value we want
		indexA = 2 * n
		indexB = 2 * n + 1

		try:
			valA = 2 * values[n]
			values[indexA] = valA
		except:
			pass

		try:
			valB = values[n] - (3 * values[n + 1])
			values[indexB] = valB
		except:
			pass

	print(values)

	"""runningSum = 0
	for n in range(1, N + 1):
		runningSum += values[n]
	print(runningSum)"""

	runningSum = 0
	for key in values.keys():
		runningSum += values[key]
	print(runningSum)

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
