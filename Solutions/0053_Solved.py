# Project Euler problem 53 solved 0343KST 27Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def countCombinations(n, r): return int((EM.factorial(n) / (EM.factorial(r) * EM.factorial(n - r))))

def logic():
    maximum = 100
    overcount = 0

    for n in range(1, maximum + 1):
        for r in range(1, n + 1):
            if countCombinations(n, r) > 10 ** 6: overcount += 1

    return overcount

solution = Solution(value = 4075, placement = 29473)
solution.logic = logic
solution.run()
