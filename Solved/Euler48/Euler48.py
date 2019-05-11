def number():
    value = 0
    for x in range(1, 1001):
        value+=x**x
    return value

print str(number())[-10:]
