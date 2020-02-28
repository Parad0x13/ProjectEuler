# Project Euler problem 35 solved 1253KST 25Oct13
# When I solved the problem I advanced to level 2
# Only 25921 members (7.41%) had made it that far at the time

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    primes = set(EM.primesUnder(10 ** 6))
    circularPrimes = []

    for prime in primes:
        values = EM.circularValues(prime)
        if set(values).issubset(primes):
            circularPrimes.append(prime)

    return len(circularPrimes)

solution = Solution(value = 55, placement = 4026)
solution.logic = logic
solution.run()
