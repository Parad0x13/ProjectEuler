from Euler.Solution import Solution
import Euler.Math as EM
import sys

def logic():
    n = 1
    goal = 500
    while True:
        triangle = EM.figurateNumber(3, n)
        divisors = EM.divisors(triangle)
        if len(divisors) > goal: return triangle
        n += 1

solution = Solution(value = 76576500, placement = None)
solution.logic = logic
solution.run()
