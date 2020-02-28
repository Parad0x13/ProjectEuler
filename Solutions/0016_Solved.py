from Euler.Solution import Solution
import Euler.Math as EM

def logic():
	exponential = 2 ** 1000
	summed = str(exponential)
	return sum(map(int, summed))

solution = Solution(value = 1366, placement = None)
solution.logic = logic
solution.run()
