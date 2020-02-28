from Euler.Solution import Solution
import Euler.Math as EM

def number():
    value = 0
    for x in range(1, 1001):
        value += x ** x
    return value

def logic():
	return int(str(number())[-10:])

solution = Solution(value = 9110846700, placement = None)
solution.logic = logic
solution.run()
