# [TODO] Aparantly fib numbers can be generated in O(logN) however I don't really understand the implementation

# [NOTE] Not needed but I like this implementation
fibs = [1, 1]
def fib(n):
    if len(fibs) >= n: return fibs[n - 1]
    fibs.append(fibs[-2] + fibs[-1])
    return fib(n)

print("Searching...")
pandigital = set("123456789")
n = 3
a = b = 1
while True:
    n += 1

    # [TODO] Find out if there's a better way I can do this implace
    c = a + b
    a = b
    b = c

    val = str(b)
    head = val[:9]
    tail = val[-9:]

    if set(head) != pandigital or set(tail) != pandigital: continue

    print(n - 1)
    break

print("Done")
