import psyco
psyco.full()

maxVal = 0

def isPalindrome(number):
    if str(number) == str(number)[::-1]:
        return 1
    else:
        return 0

def Dec2Binary(n):
    bStr = ""
    while n > 0:
        bStr = str(n % 2) + bStr
        n = n>>1
    return bStr

if isPalindrome(583) and isPalindrome(Dec2Binary(583)):
    print "YES!"

finalSum = 0
for x in range(1000000):
    if isPalindrome(x) and isPalindrome(Dec2Binary(x)):
        finalSum+=x

print "FinalSum = %i" % (finalSum)

raw_input("Press Enter")
