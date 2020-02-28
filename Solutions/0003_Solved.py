from Euler.Solution import Solution
import Euler.Math as EM
import math

def logic():
    val = 600851475143
    primeFactors = EM.primeFactors(val)
    return max(primeFactors)

solution = Solution(value = 6857, placement = None)
solution.logic = logic
solution.run()
