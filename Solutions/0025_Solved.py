from Euler.Solution import Solution
import Euler.Math as EM

def logic():
	fibonacci = 1
	old = fibonacci
	iteration = 2

	while len(str(fibonacci)) < 1000:
		tempNum = fibonacci
		fibonacci += old
		old = tempNum
		iteration = iteration + 1

	return iteration

solution = Solution(value = 4782, placement = None)
solution.logic = logic
solution.run()
