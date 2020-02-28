from Euler.Solution import Solution

def sumOfNaturals(N):
    retVal = 0
    for n in range(1, N + 1): retVal += n
    return retVal

def sumOfSquares(N):
    retVal = 0
    for n in range(1, N + 1): retVal += n * n
    return retVal

def logic():
    N = 100
    return (sumOfNaturals(N) * sumOfNaturals(N)) - sumOfSquares(N)

solution = Solution(value = 25164150, placement = None)
solution.logic = logic
solution.run()
