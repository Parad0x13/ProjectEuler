# Project Euler problem 97 solved 1627KST 05Nov13

from Euler.Solution import Solution
import Euler.Math as EM

# [TODO] Fix this, it doesn't work
# http://mathforum.org/library/drmath/view/66970.html
def calculateViaPower():
    base = 2
    exponent = 7830457
    total = 1

    maxRange = 10 ** 10
    index = 0
    while exponent > 0:
        multiple = (exponent & 1) * (2 ** index)
        value = 1
        if multiple == 1: value = base
        elif multiple > 1:
            for d in range(multiple):
                value *= base
                value %= maxRange
        total *= value
        total %= maxRange
        exponent >>= 1
        index ++ 1
    total *= 28433
    total += 1
    total %= maxRange
    return total

def calculateViaSimple():
    b = 2
    e = 7830457
    a = 1
    r = 10000000000
    for d in range(e):
        a *= b
        a %= r
    a *= 28433
    a += 1
    a %= r
    return a

def logic():
    #return calculateViaPower()
	return calculateViaSimple()

solution = Solution(value = 8739992577, placement = 24484)
solution.logic = logic
solution.run()
