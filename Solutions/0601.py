from Euler.Solution import Solution
import Euler.Math as EM

def streak(n):
    count = 1
    while True:
        if (n + count) % (count + 1) != 0: break
        count += 1
    return count

def numStreaks(s, N):
    retVal = 0
    for n in range(2, N)
        count = streak(n)
        if count == s: retVal += 1
    return retVal

def logic():
	total = 0
	for i in range(1, 31):
		num = numStreaks(i, pow(4, i))
		total += num
		print("i of {} yields {}".format(i, num))

	print("Done with {} total".format(total))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
