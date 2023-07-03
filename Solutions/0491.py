from Euler.Solution import Solution
import Euler.Math as EM

def logic():
    # We can skip ahead to where 11 divisors start by finding the minimum value to which multiples of 11 reach 10 digits long
    # 20 digits because the value has to be double pandigital
    # Likewise we can find the largest multiple as well
    # This will be 10**19 // 11 + 1, or 90909091
    # The largest multiple would thus be 10**20 // 11
    # The number of permutations for this is 20! which is 19 digits long so... yea not gonna brute force that

    max = 10**19
    leastMultiple = max // 11 + 1
    largestMultiple = (max * 10) // 11

    print(max)
    print(leastMultiple)
    print(largestMultiple)
    print(largestMultiple - leastMultiple)

    for n in range(leastMultiple, largestMultiple):
        val = n * 11
        a = str(val)
    print("ended")

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
