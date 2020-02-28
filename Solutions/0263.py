from Euler.Solution import Solution
import Euler.Math as EM

def divisorsOf(x):
    divisors = []
    for d in range(1, x + 1):
        if x % d == 0:
            divisors.append(d)
    return divisors

def isDistinctDivisor(divisorArray):
    val = 0
    for d in range(1, len(divisorArray) + 1):
        print("I wonder whats the best way to do this...")

def logic():
	isDistinctDivisor(divisorsOf(6))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
