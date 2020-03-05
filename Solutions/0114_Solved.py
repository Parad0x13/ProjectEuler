# Project Euler problem 114 solved 1325KST 12Nov13
# I was astounded when I clicked the check answer button and found I had got it correct
# I didn't expect that the sequence I had found (http://oeis.org/A005252) was the right one
# I still have no idea why this sequence is correct but by experimenting I was able to solve it

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    a = [1, 1, 1, 1]
    for n in range(4, 60): a.append(2 * a[n - 1] - a[n - 2] + a[n - 4])
    return a[50 + 1]

solution = Solution(value = 16475640049, placement = 5319)
solution.logic = logic
solution.run()
