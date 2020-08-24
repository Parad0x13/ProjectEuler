from Euler.Solution import Solution
import Euler.Math as EM

import cProfile

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
	newDelta = 1
	prevDelta = newDelta
	#stillCoin = False
	while True:
		c = coin(n)
		isCoin = True if c < coins[-1] else False

		if isCoin:
			foundNs.append(n)
			coins.append(c)
			cDelta = coins[-2] - coins[-1]
			#cDeltaRatio = coins[-2] / coins[-1]    # cDelta doesn't seem to be very helpful to reverse how much I should increase n by
			nDelta = foundNs[-1] - foundNs[-2]
			nDeltaRatio = nDelta / prevDelta
			print("{} n:{}\t\tc:{}\tsum {}\t{:.2f}\tnDelta {} cDelta {}".format(len(coins), n, c, sum(coins), nDeltaRatio, nDelta, cDelta))
			#print("{} n:{}\t\tc:{}\tsum {}\t{:.2f}\tnDelta {} cDelta {}".format(len(coins), n, c, sum(coins), cDeltaRatio, nDelta, cDelta))

			newDelta = nDelta    # Adjust the delta to try and skip to the next value, otherwise return newDelta back to 1 and keep seeking
			prevDelta = newDelta
			#stillCoin = True
		else:
			#if stillCoin: n = foundNs[-1] * 2    # This might only be a very small speedup...
			#stillCoin = False
			newDelta = 1

		n += newDelta

solution = Solution(value = None, placement = None, profile = True)
solution.logic = logic
solution.run()
