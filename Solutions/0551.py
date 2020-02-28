from Euler.Solution import Solution
import Euler.Math as EM

import cProfile
from line_profiler import LineProfiler

def digitSum(n):
    r = 0
    while n: r, n = r + n % 10, n // 10
    return r

def count():
    #N = 10                  # Should be 62
    #N = 100                 # Should be 1205
    #N = 1000                # Should be 16577
    N = 1000000             # Should be 31054319
    #N = 10000000            # Should be 355356611
    #N = 100000000           # Should be 4047602471
    #N = 1000000000          # Should be 45063267436
    #N = 10000000000         # Should be ???
    #N = 1000000000000000    # Goal

    #largestPossible = len(str(9 * len(str(N))))
    largestPossible = 4    # Don't know how to optimize this, but I'm assuming cache size is the issue?
    power = pow(10, largestPossible)

    # Which is faster? A dictionary or a list?
    # Seems maybe dicts are faster? How does THAT work?!
    cache = {}
    for n in range(power): cache[n] = digitSum(n)
    print("Finished calculating cache")

    #cache = []
    #for n in range(power): cache[n] = digitSum(n)
    #print("Finished calculating cache")

    current = 1
    head = headSum = headPrior = tail = 0

    # Can I optimize out of for loop's overhead? I tried while True with an interator variable and that was slower
    for n in range(1, N):
        """
        # Less naive approach
        # This seems to work really well for lower N, not sure why it derps with larger NameError
        chunks = current
        while chunks:
            chunk = chunks % power
            chunks //= power
            current += cache[chunk]
        continue
        """

        head = current // power    # Can I optimize this out?
        tail = current % power

        if head > headPrior:
            headPrior = head    # We 'could' just do prior += 1 but this works too and seems to be just as fast

            # We can avoid recalculating this, but it adds needless checks the larger N is. Need to speed test this
            #if headPrior in cache: headSum = cache[headPrior]
            #else: headSum = digitSum(headPrior)
            headSum = digitSum(headPrior)

        current += cache[tail] + headSum
    print("N of {} results in {}, calculated cache size of {}".format(N, current, len(cache)))

    """
    # Naive approach
    current = 1
    for n in range(1, N): current += digitSum(current)
    print(current)
    """

def logic():
	#cProfile.run("count()")
	lp = LineProfiler()
	wrapper = lp(count)
	wrapper()
	lp.print_stats()

	# How am I supposed to calculate 10^15 if I can't even LOOP through that much in any reasonable time?
	def test():
		for N in range(1, 10):
			power = pow(10, N)
			for n in range(1, power):
				continue
			print("Done with 10^{}".format(N))
	#cProfile.run("test()")

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
