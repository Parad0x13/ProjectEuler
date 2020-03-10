# Project Euler problem 65 solved 2039KST 04Nov13

from Euler.Solution import Solution
import Euler.Math as EM

# http://oeis.org/search?q=1%2C1%2C2%2C3%2C8%2C11%2C19%2C87%2C106%2C193&sort=&language=english&go=Search
def generateNext(a):
    n = len(a)
    option = n % 3
    if option == 0: a.append(a[n - 1] + a[n - 2])
    if option == 1: a.append(2 * (n - 1) * a[n - 1] // 3 + a[n - 2])
    if option == 2: a.append(a[n - 1] + a[n - 2])
    return a

def logic():
    numerators = [1, 1]
    for d in range(100): numerators = generateNext(numerators)

    answer = EM.digitSum(numerators[-1])
    return answer

solution = Solution(value = 272, placement = 13848)
solution.logic = logic
solution.run()
