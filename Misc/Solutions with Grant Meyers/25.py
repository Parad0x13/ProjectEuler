a = 1
b = 1
index = 2
while True:
    c = a + b
    a = b
    b = c
    index += 1
    if len(str(b)) == 1000:
        print(index, b)
        break
