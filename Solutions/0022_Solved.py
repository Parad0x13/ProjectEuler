# Solved 07Oct13

from Euler.Solution import Solution
import Euler.Math as EM

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def letterScore(string):
    retVal = 0
    for letter in string.upper():
        if letter not in alphabet: continue    # Hah... they tried to trick me!
        retVal += alphabet.index(letter) + 1
    return retVal

def logic():
    data = open("./resources/0022_names.txt").read()
    names = data.split(",")
    names.sort()

    total = 0
    for d in range(len(names)):
        score = letterScore(names[d]) * (d + 1)
        total += score
    return total

solution = Solution(value = 871198282, placement = 59759)
solution.logic = logic
solution.run()
