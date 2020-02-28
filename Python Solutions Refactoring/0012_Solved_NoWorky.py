from Euler.Solution import Solution
import math

def findTriangle(number):
    triangle = 0
    for x in range(1, number + 1):
        triangle += x
    return triangle

def findDivisors(number):
    array = []
    for x in range(1, number+1):
        if number % x == 0:
            array.append(x)
    return array

buff = 0
def divisorsOfTheTriangleOf(number):
    global buff
    triangle = 0
    amount = 0
    if not buff:
        for x in range(1, number + 1):
            triangle += x
        buff = triangle
    else:
        buff += number
        triangle = buff
    for x in range(1, triangle + 1):
        if triangle % x == 0:
            amount += 1
    return amount

def logic():
	maxDivisors = 0
	print("Calculating... Program not optimized, this may take awhile...")
	x = 0
	while maxDivisors < 500:
		divisors = divisorsOfTheTriangleOf(x)
		if divisors > maxDivisors:
			print("Value: {}. New maxDivisor from Triangle {} with {} Divisors".format(x, findTriangle(x), divisors))
			maxDivisors = divisors
		x += 1

solution = Solution(76576500)
solution.logic = logic
solution.run()
