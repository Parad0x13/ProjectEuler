# Project Euler problem 43 solved 0132KST 25Oct13

from Euler.Solution import Solution
import Euler.Math as EM
from itertools import permutations

primes = EM.primesUnder(18)
def isValid(string):
    stride = 3
    for d in range(1, len(string) - stride + 1):
        current = string[d : d + stride]
        prime = primes[d - 1]
        value = int(current)
        if value % prime != 0: return False
    return True

def logic():
    total = 0
    perms = list(permutations("0123456789"))
    for perm in perms:
        perm = "".join(perm)
        if isValid(perm): total += int(perm)
    return total

solution = Solution(value = 16695334890, placement = 26241)
solution.logic = logic
solution.run()
