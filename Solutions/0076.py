# My initial attempts at this were done by hand for f(1 - 10) and I got the sequence 0, 1, 2, 4, 6, 8, 13, 21, 27, 34
# I couldn't find this in OEIS so instead I looked up the delta between the values and found sequence A072987 that was similar
# I implemented it below but it wasn't the correct answer...
# Not for 5327 nor for 5450

# This might be helpful: https://www.math.upenn.edu/~wilf/PIMS/PIMSLectures.pdf

# Looks like this is a known issue that seems to have no known closed form solution. This means I have to find other ways of calculating them and a few examples of how are outlined in this pdf:
# https://pdfs.semanticscholar.org/df22/b005a381c7b837e781926589842dde8d8f80.pdf
# I guess the problem being asked is 'calculate unrestricted partitions'

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
	e = 2
	fibmods = [1, 1]
	for n in range(10 ** e):
		n = len(fibmods) + 1
		fibmods.append((fibmods[-1] % (n - 1)) + (fibmods[-2] % (n - 2)))
	sequence = [1, 2, 4, 6, 8]
	for n in range(5, 10 ** e): sequence.append(sequence[-1], + fibmods[n])
	for n in range(len(sequence)): print("{} = {}".format(n + 1, sequence[n]))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
