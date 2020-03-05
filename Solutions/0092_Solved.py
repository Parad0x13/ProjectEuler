# Project Euler problem 92 solved 2157KST 11Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def nextInChain(n):
    retVal = 0
    while n > 0:
        digit = n % 10
        retVal += digit * digit
        n //= 10
    return retVal

def findEnd(n):
    assert n > 0
    while True:
        if n == 1: break
        if n == 89: break
        n = nextInChain(n)
    return n

def logic():
    count = 0
    for n in range(1, 10 ** 7):
        if findEnd(n) == 89: count += 1
    return count

solution = Solution(value = 8581146, placement = 19941)
solution.logic = logic
solution.run()
