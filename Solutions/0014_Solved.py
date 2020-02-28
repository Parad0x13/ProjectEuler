from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    limit = 1000000
    largestChain = 0
    largestValue = 0
    for x in range(1, limit + 1):
        newLength = EM.collatzSequenceLength(x)
        if newLength > largestChain:
            largestChain = newLength
            largestValue = x
    return largestValue

solution = Solution(value = 837799, placement = None)
solution.logic = logic
solution.run()
