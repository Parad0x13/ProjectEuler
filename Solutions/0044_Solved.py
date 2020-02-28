# Project Euler problem 44 started 20Oct13 and solved 1502KST 25Oct13
# This could be improved by caching the pentagonal numbers, but it works fine without it for now

from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    Pj = 1
    while True:
        Pk = 1
        Pj_pent = EM.pentagonalNumber(Pj)
        while Pk < Pj:
            Pk_pent = EM.pentagonalNumber(Pk)
            added = Pj_pent + Pk_pent
            delta = Pj_pent - Pk_pent
            if EM.isNumberPentagonal(added) and EM.isNumberPentagonal(delta): return delta
            Pk += 1
        Pj += 1

solution = Solution(value = 5482660, placement = 25366)
solution.logic = logic
solution.run()
