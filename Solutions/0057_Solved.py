# Project Euler problem 57 solved 1350KST 27Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def calculateNext(input):
    assert len(input) >= 2
    input.append(2 * input[-1] + input[-2])
    return input

def logic():
    numerators = [3, 7]
    denominators = [2, 5]

    for d in range(1000 - 2):
        numerators = calculateNext(numerators)
        denominators = calculateNext(denominators)

    count = 0
    for d in range(len(numerators)):
        numerator = numerators[d]
        denominator = denominators[d]
        if len(str(numerator)) > len(str(denominator)): count += 1
    return count

solution = Solution(value = 153, placement = 19123)
solution.logic = logic
solution.run()
