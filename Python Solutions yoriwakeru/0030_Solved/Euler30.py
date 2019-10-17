import psyco
psyco.full()

def evalNumber(number):
    value = 0
    for x in range(0, len(str(number))):
        value += int(str(number)[x])**5
    if number == value:
        return 1
    else:
        return 0

array = []
finalSum = 0

#It just so happens 1000000 finds all numbers, don't know why exactly though
for x in range (2, 200000):
    if evalNumber(x):
        print "%i works!" % (x)
        finalSum += x
        array.append(x)

print "Final Accumulated sum is %i" % (finalSum)

raw_input("Press Enter")
