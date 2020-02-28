from Euler.Solution import Solution
from math import sqrt    # [NOTE] Isn't this redundant?
from itertools import *
from math import *

import psyco
psyco.full()

#Global Variables
pivotCap=10000
FoundPivots=0
Sum_Pivots=0
kStart=1
k=1
m=1
n=0

array=[]

# [NOTE] This was in the original code but I don't want it doing this... But I kept it in for reference
#SaveFile = open('Euler261_Output.txt', 'w')
#print >>SaveFile, "Attempting Calculation of all Square Pivots of range %i to %i" % (kStart, pivotCap)

def returnPivotSquares(pivot, window):
    return sum(imap(lambda x:(pivot+x)**2, range(1,window+1)))

#Function no longer used
def returnPivotSquaresLeft(pivot, window):
    total=0
    for x in range(1, window+1): #Needs to be window+1 because it will loop until it hits window then stop
        total+=(pivot-x)**2
#        total+=array[pivot-x]
    return total

def returnPivotSquaresLeftSlideWindow(pivot, window, value):
    total=value
    total+=(pivot-window)**2
    return total

def returnPivotSquaresRight(pivot, n, window):
    total=0
    for x in range(1, window+1): #Needs to be window+1 because it will loop until it hits window then stop
        total+=(pivot+n+x)**2
#        total+=array[pivot+n+x]
    return total
#    total = sum((pivot+n+x)**2 for (pivot+n+x) in xrange(1, window+1))

#def returnPivotSquaresRight(pivot, n, window):
#    return sum(imap(lambda x:(pivot+x)**2, range(1,window+1)))

#Probably can be optimized more by not erasing buffer after each window change
def returnPivotSquaresRightSlideWindow(pivot, n, window, value):
    total=value
#    total-=(array[pivot+n])
#    total+=(array[pivot+n+window])
    total-=(pivot+n)**2
    total+=(pivot+n+window)**2
    return total

def FindSquarePivots():
    global FoundPivots
    global Sum_Pivots
    LocalFoundPivots = 0
    LocalSum_Pivots = 0
    PivotSquaresRightCalculated = bool(0)
    PivotSquaresLeftCalculated = bool(0)

#    global array
#    for x in range(0, pivotCap<<1):
#        array.append(x**2)

    for k in xrange(kStart, pivotCap+1, 1):
        m=1
        PivotSquaresLeftCalculated=0
        while(m<LocalFoundPivots+3):
#        while(m<sqrt(k)+1):
            if not PivotSquaresLeftCalculated:
#                leftPivot = returnPivotSquaresLeft(k, m)+k**2
                leftPivot=((k-1)**2)+k**2
#                leftPivot=array[k-1]+array[k]
                PivotSquaresLeftCalculated=1
            else:
                leftPivot = returnPivotSquaresLeftSlideWindow(k, m, leftPivot)
            PivotSquaresRightCalculated=0
            n=0

            ############################################################MAJOR################################
            leftMax = int(sqrt(leftPivot))
            while(n<leftMax):
                if not PivotSquaresRightCalculated:
                    rightPivot = returnPivotSquaresRight(k, n, m)
                    #rightPivot = returnPivotSquares(k, m)
                    #rightPivot = sum(imap(lambda x:(k+x)**2, range(1,m+1)))
                    PivotSquaresRightCalculated=1
#                    ~PivotSquaresRightCalculated
                else:
                    rightPivot = returnPivotSquaresRightSlideWindow(k, n, m, rightPivot)
                if rightPivot>leftPivot:
                    n=leftPivot #Keep this in just in case
                    break
                if leftPivot==rightPivot:
                    print "%i is in FACT a Square-Pivot of window size %i, at max of %i, for range %i" % (k, m, LocalFoundPivots+3, n)
                    print >>SaveFile, "%i is in FACT a Square-Pivot of window size %i, at max of %i, for range %i" % (k, m, LocalFoundPivots+3, n)
                    LocalFoundPivots=LocalFoundPivots+1
                    LocalSum_Pivots+=k
                    m=k #This stops calculating after value has been found
                    n=leftPivot #Breaks the 'n' while loop
                    break
                n+=1
            m+=1
    FoundPivots = LocalFoundPivots
    Sum_Pivots = LocalSum_Pivots
    print "Number of found Square-Pivots up to %i is %i whos added sums amount to: %i" % (pivotCap, FoundPivots, Sum_Pivots)

def logic():
	FindSquarePivots()

solution = Solution(0)
solution.logic = logic
solution.run()
