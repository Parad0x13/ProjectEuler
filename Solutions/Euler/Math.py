import math

ALG_BRUTEFORCE = "BRUTEFORCE"

def isPrime_BruteForce(n):
    if n == 0 or n == 1: return False

    limit = int(math.sqrt(n)) + 1
    for x in range(2, limit):
        if n % x == 0:
            return False

    return True

def isPrime(n, algorithm = ALG_BRUTEFORCE):
    if algorithm == ALG_BRUTEFORCE:
        return isPrime_BruteForce(n)

    return None
