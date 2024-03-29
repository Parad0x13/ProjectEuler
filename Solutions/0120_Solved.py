# I solved this 2019.05.14.1650.EST

from Euler.Solution import Solution
import Euler.Math as EM

def r(a, n): return ((a - 1) ** n + (a + 1) ** n) % (a ** 2)

def maxN(a):
    period = 2 * a    # I'm not really sure why this is but there does seem to be a bounding pattern of some sort
    r_max = 0
    n_max = 0
    for n in range(period):
        R = r(a, n)
        if R > r_max:
            r_max = R
            n_max = n
    return r_max

def logic():
	lower = 3
	upper = 1000
	total = 0
	for a in range(lower, upper + 1): total += maxN(a)
	return total

solution = Solution(value = 333082500, placement = 12086)
solution.logic = logic
solution.run()
