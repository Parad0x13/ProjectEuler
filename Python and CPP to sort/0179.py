# Solved 2019.08.22.1718.EST and was the 9995th person to do so
# This took 41m 4s to calculate which is REALLY bad... however it did get the right answer
# I should reevaluate my methodology someday

from Euler.Solution import Solution
import math

# We know that divisors come in pairs so we only need to calculate up to sprt(n) and grab it's associated pair
# Outlier is if the divisor is also it's own pair, then we need to handle for that
def divisorsCount(N):
    count = 0
    for n in range(1, int(math.sqrt(N)) + 1):
        if N % n == 0:
            partner = int(N / n)    # This cast shouldn't be needed... right?
            if partner == n: count += 1
            else: count += 2
    return count

def logic():
	prior = 0
	count = 0
	for n in range(1, 10 ** 7)[::-1]:
		current = divisorsCount(n)
		if prior == None:
			prior = current
			continue

		if prior == current: count += 1
		prior = current

	return count

solution = Solution(986262)
solution.logic = logic
solution.run()
