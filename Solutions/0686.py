# There seems to be a way to calculate the first few digits with a different formula, however I do not yet understand it
# https://math.stackexchange.com/questions/89403/is-there-a-way-to-find-the-first-digits-of-a-number

from Euler.Solution import Solution
import Euler.Math as EM

def p(L, n):
	power = 1
	j = 0
	size = len(str(L))
	while True:
		a = EM.firstDigits(2 << power, size)
		if a == L:
			j += 1
			print("2^{} begins with {} and is the {}th time this happened".format(power + 1, L, j))
			if j == n: return
		power += 1

def logic():
	p(123, 678910)
	#p(12, 2)

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
