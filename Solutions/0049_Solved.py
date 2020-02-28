# Project Euler problem 49 solved 2105KST 11Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    primes = EM.primesUnder(10 ** 4)
    while primes[0] < 1000: primes = primes[1:]
    for d in range(len(primes)):
        for stride in range(1, int(10000 / 3)):
            aPrime = primes[d]
            bPrime = aPrime + stride * 1
            cPrime = aPrime + stride * 2
            if aPrime == 1487: continue    # We can safely skip aPrime being equal to 1487 as we don't really care

            if bPrime not in primes: continue
            if cPrime not in primes: continue
            if not EM.isPermutation(aPrime, bPrime): continue
            if not EM.isPermutation(bPrime, cPrime): continue

            return int("{}{}{}".format(aPrime, bPrime, cPrime))

solution = Solution(value = 296962999629, placement = 25503)
solution.logic = logic
solution.run()
