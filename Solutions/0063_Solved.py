# Finished 2019.07.30.1530.EST

from Euler.Solution import Solution
import Euler.Math as EM

def findDigitCountEqualToPower(power):
    retVal = []
    for n in range(20):
        val = n ** power
        if len(str(val)) == power: retVal.append(val)
        if len(str(val)) > power: break
    return retVal

def logic():
    found = []
    n = 1
    while True:
        values = findDigitCountEqualToPower(n)
        if len(values) == 0: break
        found += values
        n += 1

    found.remove(0)    # Not entirely sure why this pops up in there but we can manually get rid of it
    return len(found)

solution = Solution(value = 49, placement = 38635)
solution.logic = logic
solution.run()
