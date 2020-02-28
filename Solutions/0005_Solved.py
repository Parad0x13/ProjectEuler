from Euler.Solution import Solution

# [TODO] Find a more elegant solution than what I'm doing here
def logic():
    n = 1
    while True:
        if \
        n % 20 == 0 and \
        n % 19 == 0 and \
        n % 18 == 0 and \
        n % 17 == 0 and \
        n % 16 == 0 and \
        n % 15 == 0 and \
        n % 14 == 0 and \
        n % 13 == 0 and \
        n % 12 == 0 and \
        n % 11 == 0 and \
        n % 10 == 0 and \
        n % 9  == 0 and \
        n % 8  == 0 and \
        n % 7  == 0 and \
        n % 6  == 0 and \
        n % 5  == 0 and \
        n % 4  == 0 and \
        n % 3  == 0 and \
        n % 2  == 0 and \
        n % 1  == 0: return n
        n += 1

solution = Solution(value = 232792560, placement = None)
solution.logic = logic
solution.run()
