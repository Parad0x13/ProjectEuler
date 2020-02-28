# Solved 2019.08.12.1655.EST

from Euler.Solution import Solution
import Euler.Math as EM

# Uses Euclid's Method
# [TODO] See if there's a faster way to optimize for larger values, e.g. testing if n is more than half of d etc...
def HCF(n, d):
    if n == 1: return False    # Small optimization for this puzzle, this is not mathematically correct however
    while True:
        if False: pass
        elif n > d: n -= d
        elif d > n: d -= n
        elif n == d: return n

def betweenTargets(D, targetL, targetR):
    answers = 0
    targetLValue = targetL[0] / targetL[1]
    targetRValue = targetR[0] / targetR[1]
    for d in range(1, D + 1):
        for n in range(1, d):
            value = n / d
            if value > targetLValue and value > targetRValue and HCF(n, d) == 1:
                answers += 1
    return answers

def logic():
	return betweenTargets(12000, (1, 3), (1, 2))

solution = Solution(value = 7295372, placement = 22405)
solution.logic = logic
solution.run()
