# Project Euler problem 27 solved at 1543KST 17Oct13
# Ended up just solving this by brute force without optimizations. Ugly, but it worked

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    rangeVal = 1000
    primeMax = 1000
    maxN = 0
    bestA = 0
    bestB = 0
    primes = EM.primesUnder(primeMax)
    for a in range(-rangeVal, rangeVal + 1, 1):
        for b in range(-rangeVal, rangeVal + 1, 1):
            n = 0
            answer = 0
            while True:
                answer = n * n + a * n + b
                if answer > primes[-1]:
                    n -= 1
                    primeMax = int(primeMax * 1.5)
                    primes = EM.primesUnder(primeMax)
                if answer not in primes: break
                n += 1
            if n > maxN:
                maxN = n
                bestA = a
                bestB = b

    return bestA * bestB

solution = Solution(value = -59231, placement = 38985)
solution.logic = logic
solution.run()
