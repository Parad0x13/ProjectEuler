# Project Euler problem 443 started 03Nov13
# 10^15 is a VERY large number... There must be a way to find g(n-1) without calculating
# up to that point. I also searched oeis.org for g(n)'s sequence without any success

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    n1 = 13
    max = 10 ** 15

    for n in range(5, max):
        n1 = n1 + EM.GCD(n, n1)

    return n1

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
