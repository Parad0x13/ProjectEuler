# Project Euler problem 112 solved 1147KST 13Nov13
# At first I thought manually checking each number would be a horrible and inefficient way of
# doing it and would lead to no computable answer. I was wrong, it was easy and gave the answer
# right away. I wonder if there is a computational way of doing this equation, and not brute force

from Euler.Solution import Solution
import Euler.Math as EM

def isBouncy(n):
    assert n > 0

    increment = True
    decrement = True
    previous = None

    while n > 0:
        digit = n % 10

        if previous != None:
            if previous > digit: decrement = False
            if previous < digit: increment = False

        previous = digit
        n //= 10

    return (increment == False and decrement == False)
    return False

def logic():
    n = 1
    bouncyCount = 0
    while True:
        if isBouncy(n): bouncyCount += 1
        ratio = bouncyCount / n
        if ratio == 0.99: return n
        n += 1

solution = Solution(value = 1587000, placement = 12061)
solution.logic = logic
solution.run()
