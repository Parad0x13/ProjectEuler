from Euler.Solution import Solution
import Euler.Math as EM

# There's gotta be a way of approximating the next n value to check instead of brute forcing it...
# Or some underlying math thing I don't yet understand...

# 1504170715041707 = 17 * 1249 * 12043 * 5882353 4 distinct prime factors
# 4503599627370517 is prime
def coin(n):
	retVal = (1504170715041707 * n) % 4503599627370517
	return retVal

def logic():
	foundNs = [1]
	coins = [coin(1)]
	n = 2
	while True:
		c = coin(n)
		isCoin = True if c < coins[-1] else False

		if isCoin:
			foundNs.append(n)
			coins.append(c)
			ratio = foundNs[-1] / foundNs[-2]    # Trying to find patterns...
			print("{}\t\t{}\tsum {}\tdelta {}".format(n, c, sum(coins), ratio))

		n += 1

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
