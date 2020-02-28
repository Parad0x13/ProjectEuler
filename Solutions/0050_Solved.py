# Project Euler problem 50 started 13Oct13 then worked on 25Oct13
# Finally solved 1559KST 04Nov13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    maximum = 10 ** 6
    primes = EM.primesUnder(maximum)

    bestStride = []
    for index in range(len(primes)):
        for strideIndex in range(index, len(primes)):
            currentStride = primes[index : strideIndex]
            if sum(currentStride) > primes[-1]: break
            if len(currentStride) <= len(bestStride): continue
            if sum(currentStride) in primes: bestStride = currentStride

    return sum(bestStride)

solution = Solution(value = 997651, placement = 27350)
solution.logic = logic
solution.run()
