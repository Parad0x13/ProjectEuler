from Euler.Solution import Solution
import Euler.Math as EM

# https://www.wolframalpha.com/input/?i=%28%28%282%28%284%28%284%28%282%28%282%28%28%282%28a+%2F+3%29+-+1%29+%2F+3%29+%2F+3%29+-+1%29+%2F+3%29+-+1%29+%2F+3%29+%2B+2%29+%2F+3%29+%2B+2%29+%2F+3%29+-+1%29+%2F+3%29+%2F+3%29+%2F+3
pattern = "DdDddUUdDD"
letter = pattern[0]
if letter == "D": final = "a / 3"
if letter == "U": final = "(4a + 2) / 3"
if letter == "d": final = "(2a - 1) / 3"
for letter in pattern[1:]:
    if letter == "D": final = "({}) / 3".format(final)
    if letter == "U": final = "(4({}) + 2) / 3".format(final)
    if letter == "d": final = "(2({}) - 1) / 3".format(final)
print(final)

def discover(n):
    retVal = ""
    while True:
        pass

def logic():
	discover("Not Sure")

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
