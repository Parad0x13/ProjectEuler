from Euler.Solution import Solution

def isPalindrome(number):
    if str(number) == str(number)[::-1]: return True
    return False

def logic():
    maxVal = 0
    for x in range(1, 10**3):
        for y in range(1, 10**3):
            val = x * y
            if isPalindrome(val): maxVal = max(maxVal, val)

    print("Largest Palindrome made with products from 3 digit numbers is {}".format(maxVal))
    return maxVal

solution = Solution(906609)
solution.logic = logic
solution.run()
