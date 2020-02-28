# Solved 2019.08.22.1333.EST and was the 12032nd person to do so

from Euler.Solution import Solution

values = []
def palindromicConsecutiveSquares(base, limit):
    global values
    n = base
    val = 0
    while True:
        val += n * n
        if val > limit: break

        if str(val) == str(val)[::-1] and n - base > 0:
            print("{} is palindromic with base {} to {}".format(val, base, n))
            values.append(val)

        n += 1

def logic():
	for n in range(1, 100000000): palindromicConsecutiveSquares(n, limit)
	return sum(values)    # Turns out some values can be expressed as the sum of consecutive squares in multiple ways

solution = Solution(2906969179)
solution.logic = logic
solution.run()
