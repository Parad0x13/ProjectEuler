from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    n = 1
    goal = 500
    print(len(EM.divisors(50400)))
    while True:
        divisors = EM.divisors(n)
        if len(divisors) > goal: return n
        n += 1

solution = Solution(value = 76576500, placement = None)
solution.logic = logic
solution.run()
