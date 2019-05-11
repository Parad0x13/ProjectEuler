import psyco
psyco.full()

primes = []

def findPrimes(maxCheck):
    print "Calculating Primes up to %i" % (maxCheck)
    for x in xrange(2, maxCheck):
        prime = 1
        for y in xrange(2, x):
            if x%y == 0:
                prime = 0
        if prime:
            primes.append(x)

findPrimes(10000)
print "Found %i primes" % (len(primes))
print "Last prime found was %i" % (primes[len(primes)-1])

raw_input("Press Enter")
