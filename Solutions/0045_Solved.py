# Project Euler problem 45 solved 1632KST 22Oct13
# Reading on the forums it seems this equation has some
# roots in Diophantine equations. More research needed

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    found = []
    n = 1

    while True:
        triangle = EM.figurateNumber(3, n)
        if EM.isFigurateNumber(5, triangle) and EM.isFigurateNumber(6, triangle): found.append(triangle)
        if len(found) == 3: break
        n += 1

    return found[-1]

solution = Solution(value = 1533776805, placement = 34326)
solution.logic = logic
solution.run()
