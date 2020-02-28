# Solved 2019.05.14.1503.EST. Was the 12204th person to solve it

# I don't like this solution though. I think it'd be smarter to count down from 1000000
# and eliminate lines that don't work rather than calculate everything manually

from Euler.Solution import Solution
import math

# Ignores primes
def properDivisors(n):
    if n == 0: return None

    retVal = [1]
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0: retVal.extend([i, n / i])

    retVal = list(set(retVal))
    if len(retVal) == 1: return None
    return retVal

properDivisorSums = {}
def properDivisorSum(n):
    retVal = 0
    divisors = properDivisors(n)
    if divisors is not None:
        for divisor in divisors: retVal += divisor    # Can't I just sum() the list?
    return retVal

def chain(n, properDivisorSums):
    retVal = [n]

    current = n
    while True:
        if properDivisorSums[current] not in properDivisorSums: return None

        follows = properDivisorSums[current]

        if follows == 0: return None
        if follows == current: return None

        if follows in retVal:
            if retVal[0] == follows: return retVal
            else: return None

        retVal.append(follows)
        if retVal[-1] == current: break    # [BUG] I think there's something wrong with the logic here... Not sure, need to test. Certainly can't break and never return anything though
        current = retVal[-1]

def logic():
	N = 1000000
	#for n in range(N): properDivisorSums[d] = properDivisorSum(n)    # This was the original line, not sure where d was supposed to come from though...
	for n in range(N): properDivisorSums[n] = properDivisorSum(n)

	longest = []
	for n in range(properDivisorSums):
		possible = chain(n, properDivisorSums)
		if possible == None: continue

		if len(possible) > len(longest):
			print("Seed of {} results in {}".format(n, possible))
			longest = possible

	return min(longest)

solution = Solution(14316)
solution.logic = logic
solution.run()
