# Project Euler problem 99. Started 06Nov13 and solved 1500KST 17Nov13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    data = open("resources/p099_base_exp.txt", "r").read()
    data = data.split("\n")
    lines = data

    largest = 0
    largest_line = 0
    for d in range(len(lines)):
        base, exponent = lines[d].split(",")
        base = int(base)
        exponent = int(exponent)

        count = EM.digitCount_exponent(base, exponent)
        if count >= largest:
            largest = count
            largest_line = d

    return largest_line + 1

solution = Solution(value = 709, placement = 14912)
solution.logic = logic
solution.run()
