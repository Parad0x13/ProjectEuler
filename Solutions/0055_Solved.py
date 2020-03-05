# Project Euler problem 55 solved at 2305KST 09Oct13

from Euler.Solution import Solution
import Euler.Math as EM

# Maybe put this in Math.py with an explanation for what Lychrel numbers are
def isLychrel(n, limit = 50):
    for interaction in range(limit):
        n = n + int(str(n)[::-1])
        if str(n) == str(n)[::-1]: return False
    return True

def logic():
    count = 0
    for n in range(10000):
        if isLychrel(n): count += 1
    return count

solution = Solution(value = 249, placement = 26211)
solution.logic = logic
solution.run()
