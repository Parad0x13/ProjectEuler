# Project Euler problem 62 solved 1435KST 09Dec13

from Euler.Solution import Solution
import Euler.Math as EM

def sortedStringValue(n): return sorted("".join(str(n)))

def logic():
    answerPermutation = ""
    cubeStrings = []

    for d in range(1000, 10000):
        cube = d ** 3
        cubeString = sortedStringValue(cube)
        cubeStrings.append(cubeString)

        if cubeStrings.count(cubeString) == 5:
            answerPermutation = cubeString
            break

    d = 1
    while True:
        cube = d ** 3
        d += 1
        cubeString = sortedStringValue(cube)
        if cubeString == answerPermutation:
            return cube

solution = Solution(value = 127035954683, placement = 14285)
solution.logic = logic
solution.run()
