import psyco
psyco.full()

def divisorsOf(x):
    divisors = []
    for d in xrange(1, x+1):
        if x % d == 0:
            divisors.append(d)
    return divisors

def isDistinctDivisor(divisorArray):
    val = 0
    for d in xrange(1, len(divisorArray)+1):
        print "I wonder whats the best way to do this..."

isDistinctDivisor(divisorsOf(6))
