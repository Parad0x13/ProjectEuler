from Euler.Solution import Solution

def number():
    value = 0
    for x in range(1, 1001):
        value += x ** x
    return value

def logic():
	return int(str(number())[-10:])

solution = Solution(9110846700)
solution.logic = logic
solution.run()
