from Euler.Solution import Solution
import Euler.Math as EM

# [NOTE] I really need to properly implement other primality tests... Pollard-Rho doesn't seem to work
def logic():
    currentPrime = 1    # Yes I know 1 is not a prime...
    foundPrimes = []
    while True:
        currentPrime = EM.nextPrime(currentPrime)
        primeSquared = currentPrime ** 2
        reversedPrime = EM.reverseInt(primeSquared)

        if primeSquared == reversedPrime: continue    # We don't care about palindromes
        if not EM.isSquare(reversedPrime): continue

        foundPrimes.append(primeSquared)

        print("The prime {} squared is {} and reversed is {}. This makes {} found options".format(currentPrime, primeSquared, reversedPrime, len(foundPrimes)))

        if len(foundPrimes) == 50: break

    print("Found {} possibles".format(len(foundPrimes)))
    print(sum(foundPrimes))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
