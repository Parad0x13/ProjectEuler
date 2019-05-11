import psyco
psyco.full()

def sumRange(theArray):
    value = 0
    for x in range(0, len(theArray)):
        value+=theArray[x]
    return value

def divisableArray(value):
    theArray = []
    for x in range(1, value):
        if value%x == 0:
            theArray.append(x)
    return theArray

amicable = []

for x in range(1, 10000):
    if not x == sumRange(divisableArray(x)):
        if x == sumRange(divisableArray(sumRange(divisableArray(x)))):
            amicable.append(x)

print "Number of Amicable Pairs Found is: %i" % (len(amicable))
print "List of all Amicable Pairs:"

for x in range(0, len(amicable)):
    print amicable[x]

print "Sum of all pairs is: %i" % (sumRange(amicable))

raw_input("Press Enter")
