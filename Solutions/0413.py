from Euler.Solution import Solution
import Euler.Math as EM

def isOneChild(n):
    children = 0
    stride = 1

    string = str(n)
    d = len(string)
    while True:
        for i in range(d - stride + 1):
            substring = string[i : i + stride]

            if int(substring) % d == 0:
                children += 1
                if children > 1: return False

        stride += 1
        if stride > d: break

    if children != 1: return False
    return True

def evaluate(e):
    count = 0
    for n in range(1, 10 ** e):
        if isOneChild(n): count += 1
    print("10 ** {} has {} 1-child numbers".format(e, current))

def logic():
	e = 7
	evaluate(e)

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
