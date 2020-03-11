# Project Euler problem 39 solved 1055KST Oct2513

from Euler.Solution import Solution
import Euler.Math as EM

# http://en.wikipedia.org/wiki/Pythagorean_triple
def euclidPythagoreanTriple(m, n):
    assert m > n and n > 0

    a = m * m - n * n
    b = 2 * m * n
    c = m * m + n * n

    return(sorted([a, b, c]))

def logic():
    found = []
    maximum = 100
    for m in range(2, maximum):
        for n in range(1, m):
            triple = euclidPythagoreanTriple(m, n)

            # Euclid cannot generate all triples so we must multiply by a scalar
            k = 1
            while True:
                a = (triple[0] * k, triple[1] * 1, triple[2] * k)
                if sum(a) > 1000: break
                found.append(a)
                k += 1
    found = set(found)

    # Find the number of solutions maximized
    ps = [sum(triple) for triple in found]
    uniques = list(set(ps))
    largest = 0
    for unique in uniques:
        if ps.count(unique) > ps.count(largest):
            largest = unique
    return largest

solution = Solution(value = 840, placement = 33295)
solution.logic = logic
solution.run()
