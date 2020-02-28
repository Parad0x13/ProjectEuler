from Euler.Solution import Solution

def evalNumber(number):
	value = 0
	for x in range(len(str(number))):
		value += int(str(number)[x]) ** 5
	if number == value: return 1
	else: return 0

def logic():
	array = []
	finalSum = 0
	#It just so happens 1000000 finds all numbers, don't know why exactly though
	for x in range (2, 200000):
		if evalNumber(x):
			finalSum += x
			array.append(x)
	return finalSum

solution = Solution(443839)
solution.logic = logic
solution.run()
