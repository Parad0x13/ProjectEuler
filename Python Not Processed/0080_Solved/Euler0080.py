#Answer 40886. Solved 2019.08.01.1042.EST. Was the 17563rd person to solve it
from decimal import *

getcontext().prec = 110    # Some extra precision just incase

total = 0
for n in range(100):
	a = str(Decimal(n).sqrt()).replace(".", "")[:100]
	if len(a) == 100:
		for item in a: total += int(item)
print(total)
