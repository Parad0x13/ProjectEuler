# Project Euler problem 24 solved 1427KST 17Oct13
"""
    I know that this isn't so hard to do by brute force but there is also a mathematical way
	to solve it as well as outlined in the below citation. I came across this while looking
	for motivation to solve this equation. I also showed this problem to one of the Korean soldiers
	and he thought it looked complicated. I haven't told him that I've solved it yet

    Mathematic solution: http://blog.singhanuvrat.com/problems/project-euler-the-millionth-lexicographic-permutation-of-the-digits#sthash.ZqgLsUkz.dpbs

    On 18Oct13 after a bit of study I figured out how to do it by combinatorics. I understood the algorithm
	well enough to code it, but I had to write it out on paper a bunch of times and go through
	it manually to really get a decent grasp on it. Even now it alludes me and I'm angry that
	I didn't come up with it myself. I don't know if it's a problem with the way I think, or
	if the people who came up with it as a novel idea had precursor understanding of combinatorics.
	At any rate I've implemented the algorithm in the source

    Shortly after I implemented the combinatorics algorithm the Korean soldier who I brought the
	question up to came to my office and had solved the equation on paper. I was thrilled to see
	that he followed through with it, and that he was capable of solving it as well. In fact I think
	that I'm burning myself out mentally, or at least getting myself stuck in a rut, trying to solve
	equation after equation. I think with a fresh mind and thinking of different ways to solve
	this equation I could solve it on paper myself as well. I did however jump right to solving
	it on the computer so it's no surprise that the algorithm I used to solve it the first time
	was not novel. The Korean guy actually calculated the wrong number since he calculated iteration
	10^6 and not 10^60-1 (the permutation). Still, he solved it and I'm very very impressed
"""

from Euler.Solution import Solution
import Euler.Math as EM
from itertools import permutations

# Just another way of doing it, slower though
def bruteforce():
    digits = list("0123456789")
    perms = list(permutations(digits))
    answer = int("".join(perms[10 ** 6 - 1]))
    return answer

# The methodology I was able to figure out eventually
def combinatorics():
    digits = "0123456789"
    answer = ""
    digitIndexes = []
    remainder = 10 ** 6 - 1

    for d in range(len(digits), 0, -1):
        maximum = EM.factorial(d - 1)
        multiple = int(remainder / maximum)
        digitIndexes.append(multiple)
        remainder -= multiple * maximum

    for d in range(len(digits)):
        answer += digits[digitIndexes[d]]
        digits = digits.replace(digits[digitIndexes[d]], "")

    return int(answer)

def logic():
    #return bruteforce()
	return combinatorics()

solution = Solution(value = 2783915460, placement = 52240)
solution.logic = logic
solution.run()
