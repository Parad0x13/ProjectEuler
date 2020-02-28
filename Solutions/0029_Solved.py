# Solved 1010am Korea Time 09Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    minimum = 2
    maximum = 100

    vals = []
    for a in range(minimum, maximum + 1):
        for b in range(minimum, maximum + 1):
            vals.append(a ** b)
    vals = set(vals)

    return len(vals)

solution = Solution(value = 9183, placement = 46814)
solution.logic = logic
solution.run()
