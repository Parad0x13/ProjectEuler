import math

BRUTEFORCE = "BRUTEFORCE"

def divisors(n, alg = BRUTEFORCE):
    if alg == BRUTEFORCE: return divisors_bruteforce(n)

def divisors_bruteforce(n):
    retVal = []

    for x in range(1, n + 1):
        if n % x == 0:
            retVal.append(x)

    return retVal

def isPrime(n, alg = BRUTEFORCE):
    if alg == BRUTEFORCE: return isPrime_bruteforce(n)

    return None

def isPrime_bruteforce(n):
    if n == 0 or n == 1: return False

    limit = int(math.sqrt(n)) + 1
    for x in range(2, limit):
        if n % x == 0:
            return False

    return True

def primesBelow(max, alg = BRUTEFORCE):
    retVal = []
    for n in range(max + 1):
        if isPrime(n, alg):
            retVal.append(n)
    return retVal

def collatzSequenceLength(n):
    len = 1
    while n != 1:
        if n % 2 == 0: n /= 2
        else: n = n * 3 + 1
        len += 1
    return len
