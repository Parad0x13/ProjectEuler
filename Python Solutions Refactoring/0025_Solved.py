from Euler.Solution import Solution

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

solution = Solution(4782)
solution.logic = logic
solution.run()
