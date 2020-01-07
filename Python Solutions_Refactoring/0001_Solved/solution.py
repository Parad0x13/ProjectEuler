import sys; sys.path.insert(0, ".."); from helper import *

class Solution(EulerSolution):
    answer = 233168
    placement = None

    def logic(self):
        sum = 0

        for x in range(1000):
            if(x % 3 == 0 or x % 5 == 0): sum += x

        print("Iteration: {}, Sum: {}".format(x, sum))

solution = Solution()
solution.run()
