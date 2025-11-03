from Euler.Solution import Solution
import Euler.Math as EM
import math

def logic():
	#for n in range(3):
	#	print(a(n))

	#for n in range(100):
	#	if isTriangle(n):
	#		print(n)

	a(5)

#    https://www.quora.com/What-is-the-quickest-way-to-determine-if-a-number-is-a-triangular-number
#    Double the number
#    Extract the integer part of its square root
#    Multiply that part by the next integer greater than it
#    Divide the result by two
#    If the final result is your original number, it was triangular. Otherwise it wasn’t
def isTriangle(prev, n):
	m = 2 * n
	m = int(math.sqrt(m))
	m *= m + 1
	m //= 2    # Can I do integer division here? Or does it have to be floating point?

	return (m == n)

def a(N):
	if N == 0:
		return 3

	v = a(0)
	for n in range(N):
		v += n
		if isTriangle(v):
			retVal = N + 1
		else:
			# Do stuff here need to account for prev... this shouldn't be a standalone function I think

	return v

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
