# Project Euler problem 119 solved 1107KST 12Nov13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    vals = []
    baseMax = 100
    exponentMax = 10
    for b in range(2, baseMax + 1):
        for e in range(1, exponentMax + 1):
            vals.append(b ** e)
    vals = sorted(list(set(vals)))

    foundCount = 0
    for d in range(len(vals)):
        startBase = vals[d]
        base = EM.digitSum(startBase)
        total = 0
        exponent = 2
        while total < vals[-1]:
            if base == 1: break
            total = base ** exponent
            if total in vals and total == startBase:
                foundCount += 1
                if foundCount == 30: return total

            exponent += 1

solution = Solution(value = 248155780267521, placement = 5938)
solution.logic = logic
solution.run()
