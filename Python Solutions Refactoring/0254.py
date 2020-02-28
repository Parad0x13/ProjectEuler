# Practically solved, but takes TOOOOOO long to brute-force equation!

from Euler.Solution import Solution

factorials = []
def genFactorials(maxVal):
    value = 1
    for x in range(0, maxVal):
        value = 1
        for y in range(1, x+1):
            value *= y
        factorials.append(value)

#Actually Slower
def findNumLen(n):
    value = n
    length = 1
    while 1:
        value /= 10
        if value > 0: length += 1
        else: return length

def fact(n):
    value = 1
    for x in range(1, n + 1): value *= x
    return value

def f(n):
    value = 0
    lenstrn = len(str(n))
#    lenstrn = findNumLen(n)
    strn = str(n)
    for x in range(lenstrn):
        value += factorials[int(strn[x])]
    return value

def sf(n):
    value = 0
    fn = f(n)
    lenstrfn = len(str(fn))
#    lenstrfn = findNumLen(f(n))
    strfn = str(fn)
    for x in range(lenstrfn):
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
    for x in range(lenstrgi):
        value += int(strgi[x])
    return value

def logic():
	genFactorials(11)
    thisValue = 1
    for i in range(1, 151):
        print("Range = {}, Value = {}".format(i, thisValue))
        thisValue += sg(i)
    print("Finished")
    print(thisValue)

solution = Solution(0)
solution.logic = logic
solution.run()
