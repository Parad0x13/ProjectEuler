factorial = 1
for i in range(1, 101):
    factorial*=i
else:
    summed = str(factorial)
    print "Sum of Digits is: "
    print sum(map(int,summed))
