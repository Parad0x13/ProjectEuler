from Euler.Solution import Solution

def logic():
    oldNum = 1
    number = 1
    sumVal = 0

    print("Will not add to sum if Fibonacci number is not even")
    while number < 4000000:
        tempNum = number
        number += oldNum
        oldNum = tempNum

        if number % 2 == 0: sumVal += number

    return sumVal

solution = Solution(4613732)
solution.logic = logic
solution.run()
