# Project Euler problem 38 solved 1557KST 18Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def isPandigital(n):
    n = "".join(sorted(str(n)))
    return n == "123456789"

def findLargestPandigitalIn(n):
    retVal = 0
    string = ""

    for start in range(1, n):
        stride = range(start, n)

        for value in stride:
            if len(string) > 9: return retVal

            string += str(n * value)
            if len(string) == 9 and isPandigital(string):
                retVal = max(retVal, int(string))

    return retVal

def logic():
    largest = 0
    for n in range(10 ** 5):
        largest = max(largest, findLargestPandigitalIn(n))
    return largest

solution = Solution(value = 932718654, placement = 28560)
solution.logic = logic
solution.run()