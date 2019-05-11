import psyco
psyco.full()

print "Calculating..."

for a in xrange(1, 500):
    for b in xrange(1, 500):
        for c in xrange(1, 500):
            if a**2+b**2 == c**2 and a<b<c and a+b+c == 1000:
                print "Found Pythagorean Triplet with a(%i), b(%i), c(%i) who's combined product is %i" % (a, b, c, a*b*c)

raw_input("Press Enter")
