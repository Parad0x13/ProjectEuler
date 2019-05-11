fibonacci = 1
old = fibonacci
iteration = 2

while len(str(fibonacci))<1000:
#    print "Iteration %i is %i of length %i" % (iteration, fibonacci, len(str(fibonacci)))
    tempNum = fibonacci
    fibonacci+=old
    old = tempNum
    iteration=iteration+1

print "Fibonacci value:"
print fibonacci
print "Has a stringLength of:"
print len(str(fibonacci))
print "And that took this many iterations:"
print iteration
