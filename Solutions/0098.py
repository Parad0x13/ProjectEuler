from Euler.Solution import Solution
import Euler.Math as EM

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

	# Purge all non-anagram words, leaving us with 42 total anagrams. POST, STOP, SPOT is the only triplet
	toRemove = []
	for key in anagrams:
		if len(anagrams[key]) == 1: toRemove.append(key)
	for item in toRemove: del anagrams[item]

	#for key in anagrams: print(anagrams[key])
	#print(len(anagrams.keys()))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
