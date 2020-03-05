# Project Euler problem 74 solved 2151KST 27Oct13
# When I solved it the algorithm took 173.487 seconds, so improvement is needed

from Euler.Solution import Solution
import Euler.Math as EM

factorialDigits = [EM.factorial(n) for n in range(10)]

def chain(n):
	retVal = [n]

	n = chainNext(n)
	while n not in retVal:
		retVal.append(n)
		n = chainNext(n)

	return retVal

connections = {}
def chainNext(n):
	if n in connections: return connections[n]
	retVal = 0
	for digit in str(n): retVal += factorialDigits[int(digit)]
	connections[n] = retVal
	return chainNext(n)

def logic():
    count = 0
    for n in range(10 ** 6):
        if len(chain(n)) == 60: count += 1
    return count

solution = Solution(value = 402, placement = 12710)
solution.logic = logic
solution.run()
