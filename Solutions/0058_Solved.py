# Project Euler problem 58. Started 20Oct13 and solved 1640KST 04Nov13

from Euler.Solution import Solution
import Euler.Math as EM

# Doesn't need to be used in calculation, but nice to have for rendering purposes
def spiralSquare(size):
    assert size % 2 != 0

    grid = []
    for n in range(size): grid.append([""] * size)    # Why does grid = [[""] * n] * n not work?

    path = "s"
    for n in range(1, size, 2):
        path += "r" * 1
        path += "u" * n
        path += "l" * (n + 1)
        path += "d" * (n + 1)
        path += "r" * (n + 1)

    n = 0
    x = y = size // 2
    for direction in path:
        if path[n] == "s": pass
        if path[n] == "u": y -= 1
        if path[n] == "d": y += 1
        if path[n] == "l": x -= 1
        if path[n] == "r": x += 1

        grid[y][x] = n + 1
        n += 1

    return grid

def corners(size):
    assert size % 2 != 0

    found = []
    if size == 1: return found

    start = (size - 2) * (size - 2)
    end = size * size
    current = start

    # Head right
    current += 1

    # Head up, account for corner 1
    current += size - 2
    found.append(current)

    # Head left, account for corner 2
    current += size - 1
    found.append(current)

    # Head down, account for corner 3
    current += size - 1
    found.append(current)

    # Head right, account for corner 4
    current += size - 1
    found.append(current)

    return found

def logic():
    primeCount, size = 0, 3
    while True:
        values = corners(size)
        for value in values:
            if EM.isPrime(value):
                primeCount += 1

        ratio = primeCount / (size * 2 - 1)
        if ratio < 0.1: return size
        size += 2

solution = Solution(value = 26241, placement = 18365)
solution.logic = logic
solution.run()
