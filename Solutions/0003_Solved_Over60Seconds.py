from Euler.Solution import Solution
import math

# Uses the Sieve Of Eratosthenes method
# This is VERY slow and not efficient at all
primes = []
def isprime(num):
    for d in range(len(primes)):
        if num % primes[d] == 0: return False
    return True

def logic():
    theNumber = 600851475143
    primeFactor = 0
    primes.append(2)

    maxNeeded = int(math.sqrt(theNumber))
    for x in range(3, maxNeeded):
        if isprime(x):
            primes.append(x)
            if theNumber % x == 0: primeFactor = x

    return primeFactor

solution = Solution(value = 6857, placement = None)
solution.logic = logic
solution.run()
