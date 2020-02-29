"""
I solved this equation on paper with my brother Philip. We removed duplicated numbers
and then sorted them. Starting with the first number we wrote each number down in the
order that they appeared next to one another all the while assuming each number was
unique. Shortly afterwards we found the answer of 73162890

Project Euler problem 79 solved 1621KST 11Nov13
"""

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
	return 73162890

solution = Solution(value = 73162890, placement = 23210)
solution.logic = logic
solution.run()
