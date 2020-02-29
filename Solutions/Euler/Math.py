import math
from random import randint

BRUTEFORCE = "BRUTEFORCE"
OPTIMIZED = "OPTIMIZED"
POLLARDRHO = "POLLARDRHO"

def divisors(n, alg = OPTIMIZED):
    if alg == BRUTEFORCE: return divisors_bruteforce(n)
    if alg == OPTIMIZED:  return divisors_optimized(n)

def divisors_bruteforce(n):
    retVal = []

    for x in range(1, n + 1):
        if n % x == 0:
            retVal.append(x)

    return retVal

# Works by utilizing the symmetry in divisor pairs
def divisors_optimized(n):
    retVal = []
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            retVal.append(int(i))
            if n / i == i: continue
            retVal.append(int(n / i))
    return retVal

# All divisors except itself
def properDivisors(n, alg = OPTIMIZED):
    retVal = divisors(n, alg)
    try: retVal.remove(n)
    except: pass
    return retVal

def isPrime(n, alg = BRUTEFORCE):
    if alg == BRUTEFORCE: return isPrime_bruteforce(n)
    if alg == POLLARDRHO: return isPrime_pollardrho(n)

def isPrime_bruteforce(n):
    if n == 0 or n == 1: return False

    limit = int(math.sqrt(n)) + 1
    for x in range(2, limit):
        if n % x == 0:
            return False

    return True

# [BUG] Apparently this has some recursion issues? Not sure exactly but it needs to be fixed before using it
def isPrime_pollardrho(n):
    factors = primeFactors_pollardrho(n, alg = POLLARDRHO)
    if len(factors) == 1: return True
    return False

def firstNPrimes(n, alg = BRUTEFORCE):
    retVal = []
    N = 0
    while len(retVal) < n:
        if isPrime(N, alg): retVal.append(N)
        N += 1
    return retVal

def primesUnder(n, alg = BRUTEFORCE):
    retVal = []
    for N in range(n):
        if isPrime(N, alg): retVal.append(N)
    return retVal

def primeFactors(n, alg = POLLARDRHO):
    if alg == POLLARDRHO: return primeFactors_pollardrho(n)

# [TODO] This is not an elegant or effective solution
# I need to find a way to properly do this...
def primeFactors_pollardrho(n, alg = POLLARDRHO):
    retVal = []

    if n < 2: return None
    if isPrime(n): return [n]

    while True:
        factor = PollardRho(n)

        if isPrime(factor):
            retVal.append(factor)
            n /= factor
            n = int(n)

        if isPrime(n):
            retVal.append(n)
            return retVal

# https://www.geeksforgeeks.org/pollards-rho-algorithm-prime-factorization/
# PollardRho will return at least one of the factors
# This algorithm contains a fall back in case it fails to find a factor
def PollardRho(n):
    if n == 1: return n    # 1 has no factorization
    if n % 2 == 0: return 2    # Even number means one of the divisors is 2

    x = randint(2, n)    # Seed x with a random [2 to int)
    y = x
    c = randint(1, n)    # In case a composite fails in a previous attempt

    d = 1    # Candidate divisor

    # Until the prime factor isn't obtained. If n is prime, return n
    while d == 1:
        x = (x * x + c) % n    # Tortoise move

        y = (y * y + c) % n    # Hare move
        y = (y * y + c) % n

        d = GCD(abs(x - y), n)    # Check GCD of |x - y| and n

        # Retry if the algorithm fails to find prime factor with chosen x and c
        if d == n: return PollardRho(n)

    return d

def collatzSequenceLength(n):
    len = 1
    while n != 1:
        if n % 2 == 0: n /= 2
        else: n = n * 3 + 1
        len += 1
    return len

def factorial(n, alg = BRUTEFORCE):
    if alg == BRUTEFORCE: return factorial_bruteforce(n)

def factorial_bruteforce(n):
    if n == 0 or n == 1: return 1
    return factorial_bruteforce(n - 1) * n

# I would really like to test this against Lehmer's GCD algorithm
# Also I would like to add memoization to this and test that out too
def GCD(a, b, alg = BRUTEFORCE):
    if alg == BRUTEFORCE: return GCD_bruteforce(a, b)

def GCD_bruteforce(a, b):
    if b == 0: return a
    return GCD_bruteforce(b, a % b)

# All proper divisors sum to than n
def isNumberPerfect(n, alg = OPTIMIZED):
    divisors = properDivisors(n, alg)
    if sum(divisors) == n: return True
    return False

# All proper divisors sum to less than n
def isNumberDeficient(n, alg = OPTIMIZED):
    divisors = properDivisors(n, alg)
    if sum(divisors) < n: return True
    return False

# All proper divisors sum to more than n
def isNumberAbundant(n, alg = OPTIMIZED):
    divisors = properDivisors(n, alg)
    if sum(divisors) > n: return True
    return False

# [TODO] There has to be a better more elegant way of doing this...
def circularValues(n):
    retVal = []
    string = str(n)
    for n in range(len(string)):
        retVal.append(int(string))
        string = string[1:] + string[0]
    return retVal

def triangularNumber(n): return int(n * (1 * n + 1) / 2)
def pentagonalNumber(n): return int(n * (3 * n - 1) / 2)
def hexagonalNumber(n) : return int(n * (2 * n - 1) / 1)

def firstNTriangularNumbers(n): return [triangularNumber(N) for N in range(n)]
def firstNPentagonalNumbers(n): return [pentagonalNumber(N) for N in range(n)]
def firstNHexagonalNumbers(n) : return [hexagonalNumber(N) for N in range(n)]

def isNumberTriangular(n):
    N = (math.sqrt(8 * n + 1) - 1) / 2
    if N == int(N): return True
    return False

def isNumberPentagonal(n):
    N = (math.sqrt(24 * n + 1) + 1) / 6
    if N == int(N): return True
    return False

def isNumberHexagonal(n):
    N = (math.sqrt(8 * n + 1) + 1) / 4
    if N == int(N): return True
    return False

def isPermutation(a, b): return sorted(str(a)) == sorted(str(b))

def letterScore(string):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    retVal = 0
    for letter in string.upper():
        if letter not in alphabet: continue    # Just incase anything non-lettery pops up
        retVal += alphabet.index(letter) + 1
    return retVal

# [TODO] Make this actually fast...
def fib(n):
    values = [0, 1]
    for N in range(n): values.append(values[-1] + values[-2])
    return values[-1]

# [TODO] Do this mathematically instead of by using strings
def digitSum(n):
    retVal = 0
    string = str(n)
    for digit in string:
        retVal += int(digit)
    return retVal