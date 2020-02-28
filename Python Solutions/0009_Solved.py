from Euler.Solution import Solution

def logic():
    for a in range(1, 500):
        for b in range(1, 500):
            for c in range(1, 500):
                if a ** 2 + b ** 2 == c ** 2 and a < b < c and a + b + c == 1000:
                    print("Found Pythagorean Triplet with a({}), b({}), c({}) who's combined product is {}".format(a, b, c, a * b * c))
                    return a * b * c

solution = Solution(31875000)
solution.logic = logic
solution.run()
