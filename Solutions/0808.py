from Euler.Solution import Solution
import Euler.Math as EM

# [NOTE] I really need to properly implement other primality tests... Pollard-Rho doesn't seem to work
def logic():
    currentPrime = 1    # Yes I know 1 is not a prime...
    for n in range(10):
        currentPrime = EM.nextPrime(currentPrime)
        primeSquared = currentPrime ** 2
        reversedPrime = EM.reverseInt(primeSquared)

        #if not EM.isSquare(reversedPrime): continue

        print("The value {} squared is {} and reversed is {}".format(currentPrime, primeSquared, reversedPrime))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()

print()
#print(EM.reverseInt(123))
#print(str(123)[::-1])
