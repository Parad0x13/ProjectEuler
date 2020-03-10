# Solved 2019.08.22.1356.EST
# It took 425 seconds to calculate so I'm not really happy with that result
# Resources: http://www.mathblog.dk/project-euler-145-how-many-reversible-numbers-are-there-below-one-billion/
# Is it possible to stop at 10^8 since 10^9 returns the same value? What's the mathematical reason for this?

from Euler.Solution import Solution
import Euler.Math as EM
import math

"""
def logic():
	# n = 1: 0
	# n = 2: 20
	# n = 3: 120
	# n = 4: 720
	# n = 5: 720
	# n = 6: 18720
	# n = 7: 68720
	# n = 8: 608720
	# n = 9: 608720
	# There seems to be a pattern going on here of some sort... But there's no entry in OEIS

	found = 0
	for n in range(10 ** 9):
		a = str(n)
		if a[-1] <= a[0]: continue    # We can ignore any values already processed since they are symmetric!
		val = str(n + int(a[::-1]))
		if "0" in val or "2" in val or "4" in val or "6" in val or "8" in val: continue
		found += 2    # n and reverse(n)
	return found
"""

# 326 secs for 10 ** 8
# It's as though string manipulation is actually faster...

import cProfile

# isDigitPresent = 7.873
# 2 = 16.657
# 3 = 17.216

def logic():
    count = 0
    for n in range(1, 10 ** 8):
        a = n
        b = EM.reverseInt(n)

        if EM.digitCount(a) != EM.digitCount(b): continue

        c = a + b

        if EM.isDigitPresent(c, 0): continue
        if EM.isDigitPresent(c, 2): continue
        if EM.isDigitPresent(c, 4): continue
        if EM.isDigitPresent(c, 6): continue
        if EM.isDigitPresent(c, 8): continue

        count += 1

    return count

solution = Solution(value = 608720, placement = 14830, profile = True)
solution.logic = logic
solution.run()
