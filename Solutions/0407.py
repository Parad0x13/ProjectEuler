from Euler.Solution import Solution
import Euler.Math as EM

def M(n):
    largest = 0
    for a in range(n):
        val = a ** 2 % n
        if val > largest: largest = val
    return largest

def logic():
	total = 0
	for n in range(1, 10000000):
		total += M(n)

	print("Done with total of {}".format(total))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
