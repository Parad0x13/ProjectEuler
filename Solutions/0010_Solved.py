from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    primes = EM.primesBelow(2000000)
    return sum(primes)

solution = Solution(value = 142913828922, placement = None)
solution.logic = logic
solution.run()
