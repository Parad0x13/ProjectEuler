from Euler.Solution import Solution
import Euler.Math as EM

def val2array(value):
    array = []
    for x in range(0, len(str(value))):
        array.append(str(value)[x])
    array.sort()
    return array

def logic():
	for x in range(1, 200000):
		if val2array(x) == val2array(x << 1) \
		and val2array(x) == val2array(x * 3) \
		and val2array(x) == val2array(x << 2) \
		and val2array(x) == val2array(x * 5) \
		and val2array(x) == val2array(x * 6):
			return x

solution = Solution(value = 142857, placement = None)
solution.logic = logic
solution.run()
