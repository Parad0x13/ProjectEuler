from Euler.Solution import Solution

def fact(x):
    num = 1
    for x in range(2, x + 1):
        num *= x
    return num

def evalNumber(number):
    value = 0
    for x in range(len(str(number))):
        value += fact(int(str(number)[x]))
    if number == value: return 1
    else: return 0

def logic():
	array = []
	finalSum = 0

	#For some reason the answer is found below 45000, and I don't exactly know why
	for x in range(3, 45000):
		if evalNumber(x):
			finalSum += x
			array.append(x)

	return finalSum

solution = Solution(40730)
solution.logic = logic
solution.run()
