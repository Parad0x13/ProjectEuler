import math

for n in range(1000000000)[::-1]:
	a = str(n)
	padding = 9 - len(a)
	b = "0" * padding + a
	c = ""
	for digit in "123456789":
		c += digit + b[0]
		b = b[1:]
	c += "0"
	c = int(c)

	d = math.sqrt(c)
	e = int(d)
	if d == e:
		print("Found {}".format(e))
		break
