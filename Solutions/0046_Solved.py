# Project Euler problem 46 solved 2109KST 20Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    primes = EM.firstNPrimes(100)

    d = 9
    numberStillPossible = True
    while(numberStillPossible):
        if d % 2 != 0 and d not in primes:
            primeIndex = 0
            #square = 1
            foundPrime = 0
            foundSquare = 0
            while foundPrime == 0 and foundSquare == 0:
                square = 1
                while True:
                    value = primes[primeIndex] + 2 * (square * square)
                    if value == d:
                        foundPrime = primes[primeIndex]
                        foundSquare = square
                        break
                    if value > d: break
                    square += 1

                if primes[primeIndex] > d: return d

                primeIndex += 1

                if primeIndex > len(primes) - 1: primes = EM.extendPrimes(primes, 100)
        d += 1
        if d > len(primes) - 1: primes = EM.extendPrimes(primes, 100)

solution = Solution(value = 5777, placement = 26832)
solution.logic = logic
solution.run()
