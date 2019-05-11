#Practically solved, but takes TOOOOOO long to brute-force equation!

import psyco
psyco.full()

factorials = []
def genFactorials(maxVal):
    value = 1
    for x in xrange(0, maxVal):
        value = 1
        for y in xrange(1, x+1):
            value *= y
        factorials.append(value)

genFactorials(11)

#Actually Slower
def findNumLen(n):
    value = n
    length = 1
    while 1:
        value/=10
        if value > 0:
            length += 1
        else:
            return length

def fact(n):
    value = 1
    for x in xrange(1, n+1):
        value *= x
    return value

def f(n):
    value = 0
    lenstrn = len(str(n))
#    lenstrn = findNumLen(n)
    strn = str(n)
    for x in xrange(lenstrn):
        value += factorials[int(strn[x])]
    return value

def sf(n):
    value = 0
    fn = f(n)
    lenstrfn = len(str(fn))
#    lenstrfn = findNumLen(f(n))
    strfn = str(fn)
    for x in xrange(lenstrfn):
        value += int(strfn[x])
    return value

def g(i):
    value = 0
    while sf(value) != i:
        value += 1
    return value

def sg(i):
    value = 0
    gi = g(i)
    strgi = str(gi)
    lenstrgi = len(strgi)
#    lenstrgi = findNumLen(gi)
    for x in xrange(lenstrgi):
        value += int(strgi[x])
    return value

def calculateValue():
    thisValue = 1
    for i in xrange(1, 151):
        print "Range = %i, Value = %i" % (i, thisValue)
        thisValue += sg(i)
    print "Finished"
    print thisValue

print "Calculating..."
print "May not give correct answer yet..."

#import cProfile
#cProfile.run('calculateValue()')
calculateValue()

raw_input("Press Enter")
