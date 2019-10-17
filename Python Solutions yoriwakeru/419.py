import cProfile

def generate(N):
	current = "1"
	new = ""
	for n in range(N - 1):
		while True:
			val = current[0]
			count = 1

			while True:
				current = current[1:]
				if current == "": break

				if current[0] == val: count += 1
				else: break

			new += str(count) + val
			if current == "": break

		current = new
		new = ""
	print("A({}) = {}".format(N, current.count("1")))
	print("B({}) = {}".format(N, current.count("2")))
	print("C({}) = {}".format(N, current.count("3")))

#N = 10 ** 12
#for n in range(40, N + 1): cProfile.run("generate({})".format(n))
cProfile.run("generate({})".format(40))
