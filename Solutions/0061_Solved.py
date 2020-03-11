# Project Euler problem 61 started 20Nov13 and solved 21Nov13 0820KST
# I would have solved this a day earlier had the site not gone down. However even though I was able
# to calculate the answer, I was unable to ONLY calculate the answer. I also calculated 4 other
# incorrect 'answers' in my code which I couldn't track down why there were being generated. I eventually
# got fed up and by trial and error found the second answer to be correct. I'm not very happy with
# this situation but I decided to look into the forums to exact better ways of solving this equation
# before I played with the code too much and lost a possible correct answer without knowing it, thus
# pushing back the possibility of me solving this equation indefinitely

from Euler.Solution import Solution
import Euler.Math as EM
from itertools import permutations

fourDigitOrders = [None, None, None]
for order in range(3, 8 + 1):
    n = 1
    values = []

    while True:
        digit = EM.figurateNumber(order, n)
        if len(str(digit)) == 4: values.append(digit)
        if len(str(digit)) > 4: break
        n += 1

    fourDigitOrders.append(values)

# Can of course be cycled and it'll always work
def isOrdered(digits, requiresCycle = False):
    retVal = None
    perms = list(permutations(digits))
    for perm in perms:
        isValid = True

        fixed = perm
        if requiresCycle == False: fixed = fixed[:-1]
        for digit in fixed:
            a = digit
            b = perm[(perm.index(a) + 1) % len(perm)]

            if str(a)[2:] != str(b)[:2]:
                isValid = False
                break

        if isValid:
            if retVal == None: retVal = []
            retVal.append(perm)

    return retVal

def logic():
    for a in fourDigitOrders[3]:
        for b in fourDigitOrders[4]:
            if isOrdered([a, b]) == None: continue
            for c in fourDigitOrders[5]:
                if isOrdered([a, b, c]) == None: continue
                for d in fourDigitOrders[6]:
                    if isOrdered([a, b, c, d]) == None: continue
                    for e in fourDigitOrders[7]:
                        if isOrdered([a, b, c, d, e]) == None: continue
                        for f in fourDigitOrders[8]:
                            ordered = isOrdered([a, b, c, d, e, f], requiresCycle = True)
                            if ordered == None: continue
                            if len(ordered) != len(set(ordered)): continue    # All others contain duplicate values
                            return sum(ordered[0])

solution = Solution(value = 28684, placement = 11518)
solution.logic = logic
solution.run()
