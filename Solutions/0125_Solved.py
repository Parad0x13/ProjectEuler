# Solved 2019.08.22.1333.EST

from Euler.Solution import Solution
import Euler.Math as EM

values = []
def palindromicConsecutiveSquares(base, limit):
    n = base
    val = 0
    while True:
        val += n * n
        if val > limit: break
        if str(val) == str(val)[::-1] and n - base > 0: values.append(val)
        n += 1

def logic():
    limit = 10 ** 8
    for n in range(1, limit):
        palindromicConsecutiveSquares(n, limit)
    return sum(set(values))    # Turns out some values can be expressed as the sum of consecutive squares in multiple ways

solution = Solution(value = 2906969179, placement = 12032)
solution.logic = logic
solution.run()
