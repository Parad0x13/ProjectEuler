# Solved on 2020.08.24.0345.EST
# This is a VERY ugly way of going about things... but hey. I accomplished a thing

from Euler.Solution import Solution
import Euler.Math as EM
from itertools import permutations

def generatePossiblesFor(n):
	retVal = []

	perms = permutations([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], n)    # This should be precomputed, but I'm too lazy to fix it right now

	for perm in perms:
		if perm[0] == 0: continue

		val = "".join(map(str, perm))
		if EM.isSquare(int(val)): retVal.append(val)

	return retVal

def anagramsSync(a, b):
	squares = generatePossiblesFor(len(a))

	found = []

	for key in squares:
		translation = {}
		for index in range(len(key)): translation[a[index]] = key[index]

		transformed = ""
		for letter in b: transformed += translation[letter]

		if transformed in squares: found.append(transformed)

	return found

def logic():
	words = open("resources/p098_words.txt", "r").read()
	words = words.replace("\"", "")
	words = words.split(",")

	# Find all anagrams
	anagrams = {}
	for word in words:
		sort = "".join(sorted(word))
		if sort not in anagrams: anagrams[sort] = [word]
		else: anagrams[sort].append(word)

	# Purge all non-anagram words, leaving us with 42 total anagrams
	toRemove = []
	for key in anagrams:
		if len(anagrams[key]) < 2: toRemove.append(key)
	for item in toRemove: del anagrams[item]

	largest = 0

	for anagram in anagrams.keys():
		words = anagrams[anagram]
		result = anagramsSync(words[0], words[1])
		if len(result) > 0:
			for item in result: largest = max(largest, int(item))

	for anagram in anagrams.keys():
		words = anagrams[anagram]
		result = anagramsSync(words[1], words[0])
		if len(result) > 0:
			for item in result: largest = max(largest, int(item))

	return largest

solution = Solution(value = 18769, placement = 10670)
solution.logic = logic
solution.run()
