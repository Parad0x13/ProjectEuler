# Solved 2020.03.12.1642.EST

from Euler.Solution import Solution
import Euler.Math as EM

def rad(n):
    retVal = 1
    factors = set(EM.primeFactors(n))
    for factor in factors: retVal *= factor
    return retVal

def logic():
    N = 10 ** 5
    E = []
    for n in range(1, N + 1): E.append((n, rad(n)))
    E = sorted(E, key = lambda x: x[1])

    return E[10 ** 4 - 1][0]

solution = Solution(value = 21417, placement = 12635)
solution.logic = logic
solution.run()
