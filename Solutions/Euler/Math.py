import math
from random import randint

BRUTEFORCE = "BRUTEFORCE"
OPTIMIZED = "OPTIMIZED"
POLLARDRHO = "POLLARDRHO"

def isSquare(n):
    a = math.sqrt(n)
    if a == int(a): return True
    return False

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

def isAmicable(n, alg = OPTIMIZED):
	a = sum(properDivisors(n, alg))
	b = sum(properDivisors(a, alg))
	if n == b and n != a: return True
	return False

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

def nextPrime(n, alg = BRUTEFORCE):
    n += 1
    while True:
        if isPrime(n, alg): return n
        n += 1

def extendPrimes(primes, n, alg = BRUTEFORCE):
    for N in range(n):
        primes.append(nextPrime(primes[-1], alg))
    return primes

def primeFactors(n, alg = POLLARDRHO):
    if alg == POLLARDRHO: return primeFactors_pollardrho(n)

# [TODO] This is not an elegant or effective solution
# I need to find a way to properly do this...
def primeFactors_pollardrho(n):
    retVal = []

    if n < 2: return []
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
# Greatest Common Denominator
def GCD(a, b, alg = BRUTEFORCE):
    if alg == BRUTEFORCE: return GCD_bruteforce(a, b)

def GCD_bruteforce(a, b):
    if b == 0: return a
    return GCD_bruteforce(b, a % b)

# This does not seem like an elegant solution at all...
# Least Common Multiple
def LCM(vals):
    allFactors = []
    for val in vals: allFactors.append(primeFactors(val))

    uniques = []
    for factor in allFactors: uniques += factors
    uniques = set(uniques)

    counts = {}
    for factors in allFactors:
        for unique in uniques:
            count = factors.count(unique)

            if unique not in counts: counts[unique] = count
            counts[unique] = max(counts[unique], count)

    total = 1
    for unique in uniques:
        for count in range(counts[unique]):
            total *= unique
    return total

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

# http://oeis.org/wiki/Figurate_numbers, triangular numbers, tetragonal numbers (squares), pentagonal numbers, hexagonal numbers, etc...
# Figurate numbers can be generalized to: int(n * (a * n + b) / c), and can be pre-computed (0, 1, and 2 cannot be generated)
figurateGenerators = [None, None, None,
( 1,  1,  2), (1,  0, 1), (3,  -1,  2), (2, -1, 1), (5,  -3,  2), (3, -2, 1),
( 7, -5,  2), (4, -3, 1), (9,  -7,  2), (5, -4, 1), (11, -9,  2), (6, -5, 1),
(13, -11, 2), (7, -6, 1), (15, -13, 2), (8, -7, 1), (17, -15, 2), (9, -8, 1)]
def figurateNumber(order, n):
    assert order < len(figurateGenerators), "Generator for figurate of order {} does not exist".format(order)
    assert n > 0, "Cannot generate figurate of order {} for n of {}".format(order, n)

    a, b, c = figurateGenerators[order]
    return n * (a * n + b) // c

def firstNFigurateNumbers(order, n): return [figurateNumber(order, N) for N in range(1, n + 1)]

# Figurate number checks can be generalized to: (math.sqrt(a * n + b) + c) / d, and can be pre-computed (0, 1, and 2 cannot be generated)
figurateChecks = [None, None, None, (8, 1, 1, 2), (1, 0, 0, 1), (24, 1, 1, 6), (8, 1, 1, 4), (40, 9, 3, 10), (3, 1, 1, 3)]
def isFigurateNumber(order, n):
    assert order < len(figurateChecks), "Check for figurate of order {} does not exist".format(order)
    assert n > 0, "Cannot check figurate of order {} for n of".format(order, n)

    a, b, c, d = figurateChecks[order]
    N = (math.sqrt(a * n + b) + c) / d
    return N == int(N)

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

def firstDigits(n, k):
	digits = (int)(math.log10(n))
	n = (int)(n / pow(10, digits - k + 1))
	return n

# [TODO] Do this mathematically instead of by using strings
def digitSum(n):
	assert type(n) == int, "digitSum(n) will only work on integers"

	retVal = 0
	for digit in str(n): retVal += int(digit)
	return retVal

def reverseInt(n):
    """
    retVal = 0
    while n > 0:
        digit = n % 10
        retVal = (retVal * 10) + digit
        n //= 10
    return retVal
    """

    return int(str(n)[::1])    # Not sure why this is so much faster...

def digitCount(n):
    """
    assert n > 0
    return int(math.log10(n)) + 1
    """

    return len(str(n))    # Not sure why this is faster...

def digitCount_exponent(a, b): return int(1 + b * math.log10(a))

# This function is actually faster than "return (str(x) in str(d))"
def isDigitPresent(x, d):
    while x > 0:
        if x % 10 == d: return True
        x //= 10
    return False

# Determines if a number cannot be divided evenly by any square above 1
def isSquareFree(n):
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0: n //= i
        if n % i == 0: return False
    return True

"""Farey calculates all fractions between two values"""
# [TODO] Does not compute simplified versions of fractions, make it able to do this too
def Farey(N, a = (0, 1), b = (1, 1)):
    retVal = [a, b]
    for N in range(N):
        tmp = [retVal[0]]
        for n in range(len(retVal) - 1):
            a = retVal[n + 0]
            b = retVal[n + 1]
            c = tuple(map(sum, zip(a, b)))
            tmp.append(c)
            tmp.append(b)
        retVal = tmp
    return retVal
