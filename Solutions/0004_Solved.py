from Euler.Solution import Solution
import Euler.Math as EM

def isPalindrome(number):
    if str(number) == str(number)[::-1]: return True
    return False

def logic():
    maxVal = 0
    for x in range(1, 10**3):
        for y in range(1, 10**3):
            val = x * y
            if isPalindrome(val): maxVal = max(maxVal, val)

    return maxVal

solution = Solution(value = 906609, placement = None)
solution.logic = logic
solution.run()
