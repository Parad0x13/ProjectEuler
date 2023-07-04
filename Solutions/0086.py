from Euler.Solution import Solution
import Euler.Math as EM
from math import sqrt

"""
A good visualization of this problem's constrained euclidean distance issue is located here on YouTube:
    https://www.youtube.com/watch?v=Pc19PlwMLUU&ab_channel=digitalpace

It seems we only need to calculate three possible ways to move on the cuboid's faces and chose the minimum
"""
# Great naming convention...
# [NOTE] I'm only mostly confident this is correct...
def cuboidMinDistanceBetweenOppositeEdges(length, height, breadth):
    optionA = sqrt((length + height)**2 + breadth**2)
    optionB = sqrt((breadth + height)**2 + length**2)
    optionC = sqrt((breadth + length)**2 + height**2)
    return (min(optionA, optionB, optionC))

def logic():
    minimum = cuboidMinDistanceBetweenOppositeEdges(6, 5, 3)
    print(minimum)

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
