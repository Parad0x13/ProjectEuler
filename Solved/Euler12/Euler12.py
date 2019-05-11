import psyco
psyco.full()

maxDivisors = 0

def findTriangle(number):
    triangle = 0
    for x in range(1, number+1):
        triangle+=x
    return triangle

def findDivisors(number):
    array = []
    for x in range(1, number+1):
        if number%x == 0:
            array.append(x)
    return array

buff = 0
def divisorsOfTheTriangleOf(number):
    global buff
    triangle = 0
    amount = 0
    if not buff:
        for x in xrange(1, number+1):
            triangle+=x
        buff = triangle
    else:
        buff += number
        triangle = buff
    for x in xrange(1, triangle+1):
        if triangle % x == 0:
            amount += 1
    return amount

print "Calculating... Program not optimized, this may take awhile"

#for x in xrange(1, 200000):
x = 0
while maxDivisors<500:
#    divisors = len(findDivisors(findTriangle(x)))
    divisors = divisorsOfTheTriangleOf(x)
    if divisors > maxDivisors:
        print "Value: %i. New maxDivisor from Triangle %i with %i Divisors" % (x, findTriangle(x), divisors)
        maxDivisors = divisors
    x += 1

raw_input("Press Enter")
