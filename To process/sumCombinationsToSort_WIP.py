"""
def findCombinations(n):
	found = []

	currentIndex = 0
	currentReduced = n
	while currentReduced > 0:
		current = []
		index = currentIndex
		reduced = currentReduced
		while reduced > 0:
			if index == 0: prev = 1
			#else: prev = found[-1]
			#else: prev = current[index - 1]
			else: prev = reduced

			current.append(prev)
			index += 1
			reduced -= prev
		print(current)
		currentIndex += 1
		currentReduced -= 1
"""

""" Helper function for findSumCombinations() """
def findSumCombinationsRecurse(arr, index, num, reducedNum, answer, require):
	if (reducedNum < 0): return;

	if (reducedNum == 0):
		current = arr[:index]
		if require != None and require not in current: return
		answer.append(current)
		return

	prev = 1 if(index == 0) else arr[index - 1];

	for k in range(prev, num + 1):
		arr[index] = k;
		findSumCombinationsRecurse(arr, index + 1, num, reducedNum - k, answer, require);

""" Finds all the combinations that can sum to n """
def findSumCombinations(n, require = None):
	answer = []
	findSumCombinationsRecurse([0] * n, 0, n, n, answer, require);
	return answer

print(findSumCombinations(100))
