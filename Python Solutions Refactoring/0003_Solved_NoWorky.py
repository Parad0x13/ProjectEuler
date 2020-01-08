from Euler.Solution import Solution
import math

def logic():
    foundPrimes = 0
    primes = []

    # Uses the Sieve Of Eratosthenes method
    def isprime(num):
        for d in range(foundPrimes):
            if num % primes[d] == 0: return False
        return True

    theNumber = 600851475143
    primeFactor = 0

    primes.append(2)
    foundPrimes += 1

    maxNeeded = int(math.sqrt(theNumber))
    for x in range(3, maxNeeded):
        if isprime(x):
            primes.append(x)
            foundPrimes += 1
            if theNumber % x == 0: primeFactor = x

    print("Fully Calculated! Largest Prime Factor is {}".format(primeFactor))

solution = Solution(6857)
solution.logic = logic
solution.run()
