import psyco
psyco.full()

def val2array(value):
    array = []
    for x in range(0, len(str(value))):
        array.append(str(value)[x])
    array.sort()
    return array

print "Calculating..."

for x in range(1, 200000):
    if val2array(x) == val2array(x<<1) and val2array(x) == val2array(x*3) and val2array(x) == val2array(x<<2) and val2array(x) == val2array(x*5) and val2array(x) == val2array(x*6):
        print "Number %i have the same digits as when its multiplied by 2, 3, 4, 5, and 6" % (x)

raw_input("Press Enter")
