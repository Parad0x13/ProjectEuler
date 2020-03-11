# Project Euler problem 37 solved 1434KST 20Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    primes = EM.firstNPrimes(1)
    found = []

    while len(found) < 11:
        prime = primes[-1]

        isValid = True
        if len(str(prime)) < 2: isValid = False

        left = str(prime)
        right = str(prime)
        while isValid:
            left = left[:-1]
            if left == "": break
            if int(left) not in primes: isValid = False

            right = right[1:]
            if right == "": break
            if int(right) not in primes: isValid = False

        if isValid: found.append(prime)
        primes = EM.extendPrimes(primes, 1)

    return sum(found)

solution = Solution(value = 748317, placement = 33773)
solution.logic = logic
solution.run()
