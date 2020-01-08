from Euler.Solution import Solution

def logic():
    sum = 0
    for x in range(1000):
        if(x % 3 == 0 or x % 5 == 0): sum += x

    return sum

solution = Solution(233168)
solution.logic = logic
solution.run()
