# Solved 2019.08.01.1042.EST

from Euler.Solution import Solution
import Euler.Math as EM

from decimal import *

def logic():
	getcontext().prec = 110    # Some extra precision just in case

	total = 0
	for n in range(100):
		a = str(Decimal(n).sqrt()).replace(".", "")[:100]
		if len(a) == 100:
			for item in a: total += int(item)
	return total

solution = Solution(value = 40886, placement = 17563)
solution.logic = logic
solution.run()
