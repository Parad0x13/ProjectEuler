from Euler.Solution import Solution
import Euler.Math as EM
#import itertools

def allDigitalSplits(number):
	a = list(str(number))

	if number < 10:
		return [number]

	retVal = []

	for n in range(1, len(a) ):
		front = a[:n]
		back = a[len(front):]
		front = "".join(front)
		back = "".join(back)
		front = int(front)
		back = int(back)

		# We aren't interested in values that are multiplied by zero
		if front == 0: continue    # [NOTE] This check is redundant as the leading digit cannot be zero
		if back == 0: continue

		# Ensure we don't fall into a trap like "9801" as [98, 01] which properly concatenated would be 981 and therefor would not qualify
		if str(number) != str(front) + str(back): continue

		# This seems to be a pattern maybe? I have NO IDEA if this is actually true or not... This is JUST A TEST
		#if len(str(front)) > len(str(back)): break

		#if front + back > number: break    # I don't know if this is true... It might miss a case where back has a preceeding zero and qualifies. Or it just might be a dumb check to begin with

		retVal.append([front, back])

	return retVal

def logic():
	# The number of digits to search up to
	N = 16    # This is what ProjectEuler wants me to search up to... need to find a way to make this MUCH faster
	N = 7
	#N = 8

	found = []
	for number in range(10, 10**N):
		splits = allDigitalSplits(number)
		for val in splits:
			newVal = sum(val) ** 2
			if newVal == number:
				found.append(newVal)
				print("Found a 2025 number '{}' split as such: {}".format(val, val))

	print(found)
	print(sum(found))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
