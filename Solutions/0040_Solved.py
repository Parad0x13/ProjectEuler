from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    string = ""

    max = 1000000
    n = 1
    while len(string) < max:
        string += str(n)
        n += 1

    ans = 1 *\
    int(string[1 - 1]) *\
    int(string[10 - 1]) *\
    int(string[100 - 1]) *\
    int(string[1000 - 1]) *\
    int(string[10000 - 1]) *\
    int(string[100000 - 1]) *\
    int(string[1000000 - 1])
    return ans

solution = Solution(value = 210, placement = None)
solution.logic = logic
solution.run()
