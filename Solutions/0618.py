from Euler.Solution import Solution
import Euler.Math as EM

def S(k):
    n = 2
    found = []
    limitGuess = k ** 2    # When do you know when to stop?
    while True:
        val = sumOfPrimeFactors(n)
        if val > limitGuess: break

        if val == k: found.append(n)

        n += 1

    return sum(found)

def sumOfPrimeFactors(n):
    primeFactors = EM.primeFactors(n)
    return sum(primeFactors)

def logic():
    found = []
    for n in range(2 , 24 + 1):
        fib = EM.fib(n - 1)
        s = S(fib)
        print("n({}) = fib({}) yields S(k) of {}".format(n, fib, s), flush = True)
        found.append(s)
    print(sum(found))

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
