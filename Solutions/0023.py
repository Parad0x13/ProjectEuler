# Project Euler problem 23 started 16Oct13 solved 0940KST 22Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    limit = 28123

    abundants = []
    for n in range(limit):
        if EM.isNumberAbundant(n): abundants.append(n)
    abundants = list(set(abundants))

    summable = []
    for indexA in range(len(abundants)):
        for indexB in range(indexA, len(abundants)):
            a = abundants[indexA]
            b = abundants[indexB]
            if a + b < limit: summable.append(a + b)
    summable = list(set(summable))

    answer = 0
    for n in range(limit):
        if n in summable: continue
        answer += n

    return answer

solution = Solution(value = 4179871, placement = 45083)
solution.logic = logic
solution.run()
