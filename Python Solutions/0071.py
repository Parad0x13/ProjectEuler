# Solved but not with python

from Euler.Solution import Solution

# Uses Euclid's Method
# [TODO] See if there's a faster way to optimize for larger values, e.g. testing if n is more than half of d etc...
def HCF(n, d):
    if n == 1: return False    # Small optimization for this puzzle, this is not mathematically correct however
    while True:
        if False: pass
        elif n > d: n -= d
        elif d > n: d -= n
        elif n == d: return n

def leftOfTarget(D, target):
    answer = target
    targetValue = target[0] / target[1]
    currentDelta = 1000
    for d in range(1, D + 1):
        for n in range(1, d):
            value = n / d
            if value > targetValue: break    # No need to continue with the numerator after we go past the target
            delta = targetValue - value
            if delta < currentDelta and target != (n, d) and HCF(n, d) == 1:
                answer = (n, d)
                currentDelta = delta
    return answer

def logic():
	return leftOfTarget(10 ** 6, (3, 7))

solution = Solution(428570)
solution.logic = logic
solution.run()
