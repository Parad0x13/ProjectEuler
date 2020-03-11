# Project Euler problem 69 solved 1632KST 12Nov13
# Citation for Euler's Product formula: http://en.wikipedia.org/wiki/Euler%27s_totient_function
# Citation for Pi product formula notation: http://en.wikipedia.org/wiki/Arithmetical_function#Notation
# Initially I tried computing every prime factorization of every number up to 1 million but found that
# that took a VERY long time. Like 20 minutes of time to do. I noticed while the numbers were filling
# in on the screen that numbers like 990990 or 870870 or 690690 were coming up and decided that I would
# experiment with only searching d up to 1000 but checking d*1000+d and right away found that the number
# 510510 had the highest prime totient value. I tried this number on the site and found it to be correct
# I don't know WHY this works, but it does. I've left the slow code annotated as well for record

from Euler.Solution import Solution
import Euler.Math as EM

largestSearch = 1000000
primes = EM.primesUnder(largestSearch)

# [TODO] Add this to Math.py
def eulers_totient(index):
    factors = EM.primeFactors(index)
    factors = list(set(factors))

    retVal = index
    for d in range(len(factors)):
        retVal *= 1 - 1 / factors[d]
    return retVal

def logic():
    largestTotientPrime = 0
    largestTotientPrimeIndex = 0
    for d in range(1, 1000):    # Brute force check to 1000000
        num = d * 1000 + d
        totient = eulers_totient(num)   # Brute force would check totient of d
        tPrime = num / totient  # Brute force would check prime of totient of d
        if tPrime > largestTotientPrime:
            largestTotientPrime = tPrime
            largestTotientPrimeIndex = num
    return largestTotientPrimeIndex

solution = Solution(value = 510510, placement = 16428)
solution.logic = logic
solution.run()
