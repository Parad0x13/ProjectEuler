import math

BRUTEFORCE = "BRUTEFORCE"

def isPrime_BruteForce(n):
    if n == 0 or n == 1: return False

    limit = int(math.sqrt(n)) + 1
    for x in range(2, limit):
        if n % x == 0:
            return False

    return True

def isPrime(n, alg = BRUTEFORCE):
    if algorithm == BRUTEFORCE:
        return isPrime_BruteForce(n)

    return None

def primesBelow(max, alg = BRUTEFORCE):
    retVal = []
    for n in range(max + 1):
        if isPrime(n, alg):
            retVal.append(n)
    return retVal
