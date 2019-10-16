import math

def divisors(N):
	retVal = []
	for n in range(1, int(math.sqrt(N) + 1)):
		if N % n == 0:
			divd = int(N / n)
			if divd == n:
				retVal.append(n)
			else:
				retVal.append(n)
				retVal.append(divd)
	return retVal

def sigma2(n):
	retVal = 0
	for div in divisors(n):
		retVal += divd * divd
	return retVal

def summatory(n):
	retVal = 0
	for i in range(1, n + 1):
		retVal += sigma2(i)
	rturn retVal

#n = 10 ** 15
n = 10 ** 5    # Takes ~2.5 seconds, SLOW!
print(summatory(n))