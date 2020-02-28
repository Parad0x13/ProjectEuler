# Project Euler problem 41 started 22Oct13 and solved 2009KST 03Nov13

from Euler.Solution import Solution
import Euler.Math as EM
from itertools import permutations

def logic():
    digits = "1234567"    # Through trial and error I determined 12345678 and 123456789 do not have any primes
    perms = permutations(digits)

    largest = 0
    for perm in perms:
        perm = int("".join(perm))
        if EM.isPrime(perm): largest = max(perm, largest)
    return largest

solution = Solution(value = 7652413, placement = 30817)
solution.logic = logic
solution.run()
