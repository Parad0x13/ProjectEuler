# Solved 2019.08.22.1356.EST and was the 14830st person to do so
# It took 23m 8s to calculate so I'm not really happy with that result

from Euler.Solution import Solution

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

solution = Solution(608720)
solution.logic = logic
solution.run()
