# Solved 07Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    data = open("./resources/names.txt").read()
    names = data.split(",")
    names.sort()

    total = 0
    for d in range(len(names)):
        score = EM.letterScore(names[d]) * (d + 1)
        total += score
    return total

solution = Solution(value = 871198282, placement = 59759)
solution.logic = logic
solution.run()
