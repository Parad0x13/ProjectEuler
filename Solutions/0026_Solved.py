# Project Euler problem 26 solved 2313KST 03Nov13
# While working on figuring out how to solve this problem I hadn't even though
# of trying long division. It ended up being really easy once I implemented it
# but I know there are better ways out there to do this. For instance I know by
# reading some forums that you can determine the cycle instead of actually solving
# the long division. One way to speed this up would be starting the search at the top
# of max then working downwards. The max repeat cycle is n-1 so as soon as I find
# a cycle of n-1 that's the answer

from Euler.Solution import Solution
import Euler.Math as EM

def cycleOf(input):
    numerator = 1
    denominator = input
    cycle = 0
    answer = "."
    remainders = []
    evenDivisor = False

    while True:
        numerator *= 10

        fitCount = numerator / denominator
        fitValue = denominator * fitCount
        remainder = numerator % denominator

        numerator = remainder
        if remainder == 0:
            evenDivisor = True
            break

        if remainder in remainders: break
        remainders.append(remainder)
        answer += str(fitCount)
        cycle += 1

    if evenDivisor: return 0
    return cycle

def logic():
    maximum = 1000
    maxCycleDenominator = 0
    maxCycle = 0

    for d in range(2, maximum):
        cycle = cycleOf(d)
        if cycle > maxCycle:
            maxCycleDenominator = d
            maxCycle = cycle

    return maxCycleDenominator

solution = Solution(value = 983, placement = 36636)
solution.logic = logic
solution.run()
