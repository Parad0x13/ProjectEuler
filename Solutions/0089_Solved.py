# Project Euler problem 89 solved 2302KST 11Oct13
# Rule 1: Only I, X, and C can be used as the leading numeral in part of a subtractive pair
# Rule 2: I can only be placed before V and X
# Rule 3: X can only be placed before L and C
# Rule 4: C can only be placed before D and M

from Euler.Solution import Solution
import Euler.Math as EM
import math

letterValues = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

# Does not need to tightly follow the rules
def intForNumeral(numeral):
    total = 0
    lastWasSubtractive = False
    for d in range(len(numeral)):
        if lastWasSubtractive:
            lastWasSubtractive = False
            continue

        isSubtractive = False
        currentValue = letterValues[numeral[d]]
        nextValue = 0
        if len(numeral) > d + 1: nextValue = letterValues[numeral[d + 1]]

        if nextValue > currentValue: isSubtractive = True

        if isSubtractive:
            total += nextValue - currentValue
            lastWasSubtractive = True
        else:
            total += currentValue
    return total

# Must tightly follow the rules
def numeralForNumber(number):
    assert number < 10000, "Please enter a lower number"

    retVal = []
    powerVals = [
    ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
    ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
    ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
    ["", "M", "MM", "MMM", "MMMM", "MMMMM", "MMMMMM", "MMMMMMM", "MMMMMMMM", "MMMMMMMMM"]]

    e = 0
    for digit in str(number)[::-1]:
        digit = int(digit)
        retVal.append(powerVals[e][digit])
        e += 1

    retVal = "".join(retVal[::-1])
    return retVal

def logic():
    data = open("resources/0089_p089_roman.txt", "r").read()
    data = data.split("\n")
    numerals = data

    delta = 0
    for numeral in numerals:
        a = len(numeral)
        val = intForNumeral(numeral)
        b = len(numeralForNumber(val))
        delta += a - b
    return delta

solution = Solution(value = 743, placement = 10319)
solution.logic = logic
solution.run()
