# Project Euler problem 15 solved at 1350KST
# The answer to this question is the center number of a pascal triangle of size 20
# With help from http://www.robertdickau.com/lattices.html

from Euler.Solution import Solution
import Euler.Math as EM

# n!/(r!(n-r)!)
def binomialCoefficient(n, r):
	return EM.factorial(n) / (EM.factorial(r) * EM.factorial(n-r))

# (2n)!/(n!)^2
def centralBinomialCoefficient(n):
	return EM.factorial(2 * n) / (EM.factorial(n) * EM.factorial(n))

def logic():
    return int(centralBinomialCoefficient(20))

solution = Solution(value = 137846528820, placement = 79067)
solution.logic = logic
solution.run()
