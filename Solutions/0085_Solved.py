# Solved 2021.07.30.1128.EST

from Euler.Solution import Solution
import Euler.Math as EM

def freedoms(size, block):
    wFreedoms = size[0] - block[0] + 1
    hFreedoms = size[1] - block[1] + 1

    if wFreedoms < 1 or hFreedoms < 1: return None

    return (wFreedoms, hFreedoms)

# I don't like the way this is done, it actually can be calculated inplace however I don't understand the math right now
# Check out https://www.geeksforgeeks.org/number-rectangles-nm-grid/ to better understand what is happening. Then implement it
# More specifically the direct formula to count rectangles is M(M+1)(N)(N+1)/4, but I haven't implemented this
def rectangleCount(boardW, boardH):
    total = 0
    for h in range(1, boardH + 1):
        for w in range(1, boardW + 1):
            free = freedoms((boardW, boardH), (w, h))
            if free is not None:
                num = free[0] * free[1]
                total += num
    return total

def logic():
	closestBoard = (0, 0)
	closestVal = 0
	for h in range(1, 100):
		for w in range(1, 100):
			count = rectangleCount(w, h)

			if count > closestVal and count < 2000000:
				closestVal = count
				closestBoard = (w, h)

	perimeter = closestBoard[0] * closestBoard[1]
	return perimeter

solution = Solution(value = 2772, placement = 24549)
solution.logic = logic
solution.run()
