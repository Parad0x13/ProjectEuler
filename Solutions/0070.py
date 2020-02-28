from Euler.Solution import Solution
import Euler.Math as EM

factorsMemory = []
def factorsMemory(n):
    if n in factorsMemory: return factorsMemory[n]
    values = []
    p = 2
    while n >= p * p:
        if n % p == 0:
            values.append(int(p))
            n /= p
        else: p += 1
    values.append(int(n))
    factorsMemory[n] = values
    return factorsMemory(n)

def factors(n):
    values = []
    p = 2
    while n >= p * p:
        if n % p == 0:
            values.append(int(p))
            n /= p
        else: p += 1
    values.append(int(n))
    return values

def coprime(a, b):
    aFactors = factors(a)
    bFactors = factors(b)
    union = list(set(aFactors) & set(bFactors))
    if len(union) > 0: return False
    return True

def phi(n):
    count = 0
    for d in range(1, n):
        if coprime(n, d): count += 1
    return count

def logic():
	# [BUG] This doesn't account for incorrectly assessed sets that do not match digit count with some n values
	# For example phi(1226) = 612 but these are not permutations of one another
	# I've not found a fast way of calculating this outside of using sets even with secondary tests after finding possible perms
	minimum = None
	minimumN = None
	for n in range(1, pow(10, 3))[::-1]:    # I'm going backwards because it seems the lowest ratios appear near the end, not sure if this is always the case though
		val = phi(n)

		if set(str(n)) == set(str(val)):
			ratio = n / val
			if minimum == None or ratio < minimum:
				minimum = ratio
				minimumN = n
				print("phi({}) = {}\tCurrent minimum is n = {} of {}".format(n, val, ratio, minimumN, minimum))

	print("Done")

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
