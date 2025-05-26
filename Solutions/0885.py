from Euler.Solution import Solution
import Euler.Math as EM

def orderedDigits(N):
	count = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0}

	while N > 0:
		n = N % 10
		count[n] += 1
		N //= 10

	retVal = 0
	for current in range(1, 10):    # We can skip zero
		for c in range(count[current]):
			retVal *= 10
			retVal += current
	return retVal

def logic():
	S = 6    # How many digits to run up to
	total = 0
	for n in range(10 ** S):
		total += orderedDigits(n)
	print(total)

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()

"""
So let's take S = 4
The SMALLEST number would be
1
The LARGEST number you could come up with would be
4444

However how many times does for example '1' occur?
0001
0010
0100
1000
So a total of 4 times

What about '11'?
0011
0110
1100

0101
1010

1001
Total of 6 times

And '111'? Let's start high this time
1110
1101
1011
0111
Total of 4 times

And 1111?
1111
Total of 1 times

So we get a sequence of 4, 6, 4, 1
"""

"""
Let's try where S = 5
00001
00010
00100
01000
10000

00011
00110
01100
11000

00101
01010
10100
"""
# n!/(n - r)! nPR(p, r)
# But is this it?
