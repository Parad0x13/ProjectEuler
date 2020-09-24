knownChains = {}
def collatz(n):
    chain = 0
    while n != 1:
        if n % 2 == 0: n //= 2
        else: n = 3 * n + 1
        chain += 1
    return chain

largest = 0
x = 0
for n in range(1, 1000000):
    value = collatz(n)
    if value > largest:
        largest = value
        x = n
print(x)
