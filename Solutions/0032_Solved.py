# Project Euler problem 32 solved at 1800KST 17Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    # After some experimenting I found 1963 is the lowest value that finds them all
    # But why this number specifically? I don't understand mathematically why this is
    maximum = 1963
    goal = "123456789"
    found = []
    for a in range(1, maximum + 1):
        for b in range(a + 1, maximum + 1):
            c = a * b
            string = str(a) + str(b) + str(c)
            string = sorted(string)
            string = "".join(string)

            if len(string) > len(goal): break
            if string == goal: found.append(c)

    found = set(found)
    return sum(found)

solution = Solution(value = 45228, placement = 31533)
solution.logic = logic
solution.run()
