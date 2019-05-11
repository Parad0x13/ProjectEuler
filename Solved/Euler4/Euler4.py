import psyco
psyco.full()

maxVal = 0

def isPalindrome(number):
    if str(number) == str(number)[::-1]:
        return 1
    else:
        return 0

for x in xrange(1, 1000):
    for y in xrange(1, 1000):
        if isPalindrome(x*y):
            if x*y > maxVal:
                maxVal = x*y

print "Largest Palindrome made with products from 3 digit numbers is %i" % (maxVal)
