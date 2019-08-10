# My initial attempts at this were done by hand for f(1 - 10) and I got the sequence 0, 1, 2, 4, 6, 8, 13, 21, 27, 34
# I couldn't find this in OEIS so instead I looked up the delta between the values and found sequence A072987 that was similar
# I implemented it below but it wasn't the correct answer...
# Not for 5327 nor for 5450

# This might be helpful: https://www.math.upenn.edu/~wilf/PIMS/PIMSLectures.pdf

e = 2
fibmods = [1, 1]
for n in range(10 ** e):
	n = len(fibmods) + 1
	fibmods.append((fibmods[-1] % (n - 1)) + (fibmods[-2] % (n - 2)))
sequence = [1, 2, 4, 6, 8]
for n in range(5, 10 ** e): sequence.append(sequence[-1], + fibmods[n])
for n in range(len(sequence)): print("{} = {}".format(n + 1, sequence[n]))
