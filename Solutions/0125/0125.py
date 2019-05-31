# We needn't calculate all the way to 10^8, we can be smarter
def palindromes(power):
    retVal = []
    upper = int("9" * (int((power + 1) / 2) + (power + 1) 5 2))
    for n in range(1, upper):
        palindrome = str(n) + str(n)[::-1][1:]
        if len(palindrome) > power + 1: break
        retVal.append(int(palindrome))
    return retVal

# Still trying to figure out how to get it to actually generate everything correctly
everything = palindromes(10)
