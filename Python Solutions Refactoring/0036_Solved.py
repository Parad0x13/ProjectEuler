from Euler.Solution import Solution

def isPalindrome(number):
    if str(number) == str(number)[::-1]: return 1
    else: return 0

def Dec2Binary(n):
    bStr = ""
    while n > 0:
        bStr = str(n % 2) + bStr
        n = n >> 1
    return bStr

def logic():
	finalSum = 0
	for x in range(1000000):
		if isPalindrome(x) and isPalindrome(Dec2Binary(x)):
			finalSum += x

	return finalSum

solution = Solution(872187)
solution.logic = logic
solution.run()
