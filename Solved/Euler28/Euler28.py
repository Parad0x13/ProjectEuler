import psyco
psyco.full()

maxX = 1005
maxY = 1005

a = [[0 for y in range(maxY)] for x in range(maxX)]

for x in range(maxX):
    for y in range(maxY):
        a[y][x] = 0

posX = maxX/2
posY = maxY/2
radius = 1
number = 1
a[posY][posX] = 1
number += 1
for d in range(500):
    for r in range(1, radius+1):
        a[posY][posX+r] = number
        number += 1
#        print "+H: (%i, %i)" % (posX, posY)
    posX += radius
    for r in range(1, radius+1):
        a[posY+r][posX] = number
        number += 1
#        print "+V: (%i, %i)" % (posX, posY)
    posY += radius
    radius += 1
    for r in range(1, radius+1):
        a[posY][posX-r] = number
        number += 1
#        print "-H: (%i, %i)" % (posX, posY)
    posX -= radius
    for r in range(1, radius+1):
        a[posY-r][posX] = number
        number += 1
#        print "-V: (%i, %i)" % (posX, posY)
    posY -= radius
    radius += 1
#    print "PosX: %i, PosY: %i" % (posX, posY)

for r in range(1, radius):
    a[posY][posX+r] = number
    number += 1
#    print "+H: (%i, %i)" % (posX, posY)

finalSum = 0
for x in range(maxX):
    finalSum += a[x][x]
for x in range(maxX):
    finalSum += a[maxX-x-1][x]

finalSum -= 1

print "FinalSum = %i" % (finalSum)

raw_input("Press Enter")
