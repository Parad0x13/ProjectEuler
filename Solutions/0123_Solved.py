# Project Euler problem 123 solved 2307KST 27Oct13
# Granted my initial solve took much longer than a minute to run... : ( I kept that code as findHardWay()
# I then found out on the forum that you could highly simplify the equation and rewrote it accordingly

from Euler.Solution import Solution
import Euler.Math as EM

# [TODO] Find out if this actually works... I haven't tested it yet
def findHardWay():
    primes = EM.primesUnder(10 ** 6)

    largest = 10 ** 10
    offset = 21034    # Got this through trial and error : ( Also this is cheating...
    stride = 1
    for index in range(offset, len(primes), stride):
        if index % 2 == 0: continue    # Can only be caught on odd numbers
        n = index + 1
        pn = primes[index]
        mod = (((pn - 1) ** n) + ((pn + 1) ** n)) % (pn * pn)
        #if index % stride == 0: print("{} : {}".format(n, mod))
        #if mod > largest: return mod
        if mod > largest: return n


# ((Pn-1)^2 + (Pn+1)^2)%Pn^2 can be simplified:
# If n is even then modulus will equal 2P*n
# If n is odd then modulus will alway equal 2
def simplifiedAnswer(P, n):
    if n % 2 == 0: return 2
    return P * n << 1

def findEasyWay():
    primes = EM.primesUnder(10 ** 6)

    largest = 10 ** 10
    for index in range(len(primes)):
        pn = primes[index]
        n = index + 1
        mod = simplifiedAnswer(pn, n)
        if mod > largest: return n

def logic():
    #return findHardWay()
	return findEasyWay()

solution = Solution(value = 21035, placement = 5990)
solution.logic = logic
solution.run()
