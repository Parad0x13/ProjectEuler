from Euler.Solution import Solution

def sumRange(theArray):
    value = 0
    for x in range(len(theArray)):
        value += theArray[x]
    return value

def divisableArray(value):
    theArray = []
    for x in range(1, value):
        if value % x == 0:
            theArray.append(x)
    return theArray

def logic():
	amicable = []

	for x in range(1, 10000):
		if not x == sumRange(divisableArray(x)):
			if x == sumRange(divisableArray(sumRange(divisableArray(x)))):
				amicable.append(x)

	return sumRange(amicable)

solution = Solution(value = 31626, placement = None)
solution.logic = logic
solution.run()
