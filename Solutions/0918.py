"""
Wow... this one made my head swim at first!
"""

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
	N = 10 ** 2
	#a = [1, 2, -5, 4, 17, -10, -17, 8, -47, 34]
	a = [None] * (N + 1)    # This is NOT how it should be done, but I have to start somewhere. Zero all values up to some power of ten then calculate accordingly
	#a[0] = 1
	a[0] = 0
	a[1] = 1

	for n in range(1, len(a)):
		indexA = 2 * n
		indexB = 2 * n + 1

		try:
			valA = 2 * a[n]
			a[indexA] = valA
		except:
			pass

		try:
			valB = a[n] - (3 * a[n + 1])
			a[indexB] = valB
		except:
			pass

	print()
	print(a)
	print(sum(a))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
