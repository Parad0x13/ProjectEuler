from Euler.Solution import Solution

def logic():
    factorial = 1
    for i in range(1, 100 + 1): factorial *= i
    else:
        summed = str(factorial)
        return sum(map(int, summed))

solution = Solution(648)
solution.logic = logic
solution.run()
