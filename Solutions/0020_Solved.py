from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    factorial = 1
    for i in range(1, 100 + 1): factorial *= i
    else:
        summed = str(factorial)
        return sum(map(int, summed))

solution = Solution(value = 648, placement = None)
solution.logic = logic
solution.run()
