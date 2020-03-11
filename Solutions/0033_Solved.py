# Project Euler problem 33 solved 1405KST 24Oct13
# Built this specifically to be able to solve larger digit problems instead of just 2 digit ones

from Euler.Solution import Solution
import Euler.Math as EM

def commonDigit(a, b):
    a, b = str(a), str(b)
    assert len(a) == 2 and len(b) == 2

    for digit in a:
        if digit in b:
            return int(digit)

    return None

def removeDigit(val, digit):
    val, digit = str(val), str(digit)
    assert len(val) == 2 and len(digit) == 1

    val = val.replace(digit, "", 1)
    return int(val)

def logic():
    found = []
    for n in range(10, 100):
        for d in range(10, 100):
            if n == d or n > d: continue

            common = commonDigit(n, d)
            if common == None: continue
            if common == 0: continue    # Don't care about trivial cases

            nPrime = removeDigit(n, common)
            dPrime = removeDigit(d, common)

            if nPrime == 0 or dPrime == 0: continue    # num or denom of zero will never work
            if n / d == nPrime / dPrime: found.append((n, d))

    numTotal = denomTotal = 1
    for item in found:
        numTotal *= item[0]
        denomTotal *= item[1]

    gcd = EM.GCD(numTotal, denomTotal)
    return denomTotal // gcd

solution = Solution(value = 100, placement = 33023)
solution.logic = logic
solution.run()
