from Euler.Solution import Solution
import Euler.Math as EM

# Derp, confusing wording in the problem here. "more than half of its digits equal" doesn't mean equal as in divisible by 2
# but rather equal to each other digitally. This is a silly misunderstanding lol
# Brute force approach, not elegant and does not compute in a reasonable time for larger values
def isDominating(n):
	n = str(n)
	for d in "0123456789":
		if n.count(d) > len(n) // 2: return True
	return False

"""
Needs to have over half
So length of maximum, like 10**4 (10000) means 5 digits
5 // 2 = 2
So we need 5 - 2 = 3 digits to be the same, minimum
We 'should?' be able to find the value of any particular number then multiply that by 10 maybe???

Theoretically we can do this via grouping right?
So we have a 3 digit number, represented like so:
...
We can find duplicates, knowing we need at least 2 to be the same like so:
..x -> how do we deal with predicate zeros?
.xx -> yields 10 variations
x.x -> yields 10 variations
xx. -> yields 10 variations
xxx -> yields  1 variation

All possible options for 3 digit number, where 1 becomes a wildcard
000 -> passes with 1 possible
00* -> passes with 9 possible
0*0 -> passes with 9 possible
0** -> fails
*00 -> passes with 9 possible
*0* -> fails
**0 -> fails
*** -> fails

Where N = 3 we get 27 possible per digit
10 digits total means 27 * 10 = 270 total

Where N = 4 we get ?? possible per digit

0000 no
0001 no
0010 no
0011 no
0100 no
0101 no
0110 no
0111 yes
1000 no
1001 no
1010 no
1011 yes
1100 no
1101 yes
1110 yes
1111 yes
5 * 9 = 45

Seems as though every possible answer HAS to be divisible by 9
"""

"""
Keep in mind that zero itself is neither positive nor negative, so zero does not qualify as a dominating number in and of itself
Lets do this incrementally, specifically with digit counts. This is to ignore predicates

For 1 digit
0 -> no
1 -> yes with 9 variations
Yields 9 possible

For 2 digits
00 -> no
01 -> no
10 -> no
11 -> yes with 9 variations
Yields 9 possible

For 3 digits
000 -> no
001 -> no
010 -> no
011 -> yes, 9*9 variations
100 -> no
101 -> yes, 9*9 variations
110 -> yes, 9*9 variations
111 -> yes, 9 variations
Yields 252 possible

For 4 digits
0000 -> no
0001 -> no
0010 -> no
0011 -> no
0100 -> no
0101 -> no
0110 -> no
0111 -> yes, 9*9 variations
1000 -> no
1001 -> no
1010 -> no
1011 -> yes, 9*9 variations
1100 -> no
1101 -> yes, 9*9 variations
1110 -> yes, 9*9 variations
1111 -> yes, 9 variations
Yields 333 possible

Possible per digit seems to be N(9**2) + 9, however... when N = 10 this doesn't seem to work correctly
I get 4302, however the correct answer is supposed to be 21893256

For 5 digits
00000 -> no
00001 -> no
00010 -> no
00011 -> no
00100 -> no
00101 -> no
00110 -> no
00111 -> yes, 9*9*9 variations
01000 -> no
01001 -> no
01010 -> no
01011 -> yes, 9*9*9 variations
01100 -> no
01101 -> yes, 9*9*9 variations
01110 -> yes, 9*9*9 variations
01111 -> yes, 9*9 variations
10000 -> no
10001 -> no
10010 -> no
10011 -> yes, 9*9*9 variations
10100 -> no
10101 -> yes, 9*9*9 variations
10110 -> yes, 9*9*9 variations
10111 -> yes, 9*9 variations
11000 -> no
11001 -> yes, 9*9*9 variations
11010 -> yes, 9*9*9 variations
11011 -> yes, 9*9 variations
11100 -> yes, 9*9*9 variations
11101 -> yes, 9*9 variations
11110 -> yes, 9*9 variations
11111 -> yes, 9 variations

So yea... this isn't as straight forward as I thought...
"""

def possiblePerDigits(N):
	if N == 1: return 9
	if N == 2: return 9 + possiblePerDigits(N - 1)
	return N*(9**2) + 9 + possiblePerDigits(N - 1)

def logic():
	"""
	N = 3
	count = 0
	for n in range(10**N - 1):
		if isDominating(n):
			print(n)
			count += 1
	print(count)
	"""
	N = 10
	print(possiblePerDigits(N))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
