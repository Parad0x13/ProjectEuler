def fib(N):
    if N == 0: return 0
	if N == 1: return 1
	if N == 2: return 1
	a = 1
	b = 1
	for n in range(N - 2):
	    c = a + b
		a = b
		b = c
	return b

def F(N, x):
    total = 0
	for n in range(1, N + 1):
		polynomial = fib(n) * pow(x, n)
		total += polynomial
	return total

mod = 1307674368000

#n = pow(10, 15)    # Goal
#xMax = 100    # Goal

n = pow(10, 3)
xMax = 100

total = 0
for x in range(xMax + 1): total += F(n, x)
print(total)
print()
print(total % mod)
