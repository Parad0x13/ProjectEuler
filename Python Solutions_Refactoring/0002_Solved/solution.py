import sys; sys.path.insert(0, ".."); from helper import *

class Solution(EulerSolution):
    answer = 4613732
    placement = None

    def logic(self):
        oldNum = 1
        number = 1
        sumVal = 0

        print("Will not add to sum if Fibonacci number is not even")
        while number < 4000000:
            tempNum = number
            number += oldNum
            oldNum = tempNum

            if number % 2 == 0: sumVal += number

        print("Done! With a total sum of {}".format(sumVal))

solution = Solution()
solution.run()
