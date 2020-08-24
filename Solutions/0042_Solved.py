# Project Euler problem 42 solved at 2207KST 09Oct13

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    words = open("./resources/words.txt").read()
    words = words.split(",")
    words = [word.replace("\"", "") for word in words]

    count = 0
    for word in words:
        score = EM.letterScore(word)
        if EM.isFigurateNumber(3, score): count += 1
    return count

solution = Solution(value = 162, placement = 35987)
solution.logic = logic
solution.run()
