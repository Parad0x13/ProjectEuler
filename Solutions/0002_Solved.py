from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    oldNum = 1
    number = 1
    sumVal = 0

    while number < 4000000:
        tempNum = number
        number += oldNum
        oldNum = tempNum

        # Will not add to sum if Fibonacci number is not even
        if number % 2 == 0: sumVal += number

    return sumVal

solution = Solution(value = 4613732, placement = None)
solution.logic = logic
solution.run()
