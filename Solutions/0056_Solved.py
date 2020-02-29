# Project Euler problem 56 solved 0926KST 05Nov13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    maxSum = 0
    maximum = 100
    for a in range(maximum):
        for b in range(maximum):
            value = a ** b
            sum = EM.digitSum(value)
            maxSum = max(maxSum, sum)

    return maxSum

solution = Solution(value = 972, placement = 27782)
solution.logic = logic
solution.run()
