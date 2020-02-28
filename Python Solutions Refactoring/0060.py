# Solved with cpp but not in python

from Euler.Solution import Solution

primes = []
def findPrimes(maxCheck):
    print("Calculating Primes up to {}".format(maxCheck))
    for x in range(2, maxCheck):
        prime = 1
        for y in range(2, x):
            if x % y == 0:
                prime = 0
        if prime:
            primes.append(x)

def logic():
	findPrimes(10000)
	print("Found {} primes".format(len(primes)))
	print("Last prime found was {}".format(primes[len(primes)-1]))

solution = Solution(26033)
solution.logic = logic
solution.run()
