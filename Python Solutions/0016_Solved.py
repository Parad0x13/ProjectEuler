from Euler.Solution import Solution

def logic():
	exponential = 2 ** 1000
	summed = str(exponential)
	return sum(map(int, summed))

solution = Solution(1366)
solution.logic = logic
solution.run()
