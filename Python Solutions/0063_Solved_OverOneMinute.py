# Finished 2019.07.30.1530.EST as the the 38635th person to do so
# I totally guessed the max values for the ranges... but it worked!

from Euler.Solution import Solution

def logic():
	count = 0
	for x in range(1, 100):
		for n in range(1, 10000):
			val = pow(x, n)
			length = len(str(val))
			if length == n:
				count += 1
				print("#: {}^{} = {}, len = {}".format(count, x, n, val, length))
	print("Done")

solution = Solution(49)
solution.logic = logic
solution.run()
