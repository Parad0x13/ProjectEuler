# Project Euler problem 102 solved at 2348KST on 11Oct13

from Euler.Solution import Solution
import Euler.Math as EM

# Not gonna lie, not really sure how this actually works
# (x1y2 + x2y3 + x3y1 - y1x2 - y2x3 - y3x1) / 2
def area(triangle):
    retVal = 0
    retVal += triangle[0][0] * triangle[1][1]
    retVal += triangle[1][0] * triangle[2][1]
    retVal += triangle[2][0] * triangle[0][1]

    retVal -= triangle[0][1] * triangle[1][0]
    retVal -= triangle[1][1] * triangle[2][0]
    retVal -= triangle[2][1] * triangle[0][0]

    return abs(retVal / 2)

# Not gonna lie, not really sure how this actually works
# https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
def pointInsideTriangle(point, triangle):
    PAB = (point, triangle[0], triangle[1])
    PBC = (point, triangle[1], triangle[2])
    PAC = (point, triangle[0], triangle[2])

    PAB_area = area(PAB)
    PBC_area = area(PBC)
    PAC_area = area(PAC)

    if area(triangle) == PAB_area + PBC_area + PAC_area: return True
    return False

def logic():
    data = open("resources/p102_triangles.txt", "r").read()
    data = data.split("\n")
    data = data[:-1]    # Account for ending newline character

    contained = 0
    for coords in data:
        vals = coords.split(",")

        triangle = ((int(vals[0]), int(vals[1])), (int(vals[2]), int(vals[3])), (int(vals[4]), int(vals[5])))
        if pointInsideTriangle((0, 0), triangle): contained += 1

    return contained

solution = Solution(value = 228, placement = 10688)
solution.logic = logic
solution.run()
