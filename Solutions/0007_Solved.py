from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    goal = 10001
    primeCount = 0
    n = 0

    while True:
        if EM.isPrime(n):
            primeCount += 1
            if primeCount == goal:
                return n
        n += 1

solution = Solution(value = 104743, placement = None)
solution.logic = logic
solution.run()
