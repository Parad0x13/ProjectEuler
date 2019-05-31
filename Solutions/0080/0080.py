# Not sure why this isn't correct. It seems proper to me, maybe I'm not following the rules correctly or something
from decimal import *

getcontext().prec = 500    # Not sure but I think if I only do 100 digits it rounds oddly? Have to test this

total = 0
for d in range(1, 101):
    digits = Decimal(d).sqrt()
    digits = str(digits)
    if "." in digits:
        digits = digits.split(".")[1]
        digits = digits[:100]
        val = 0
        for digit in digits: val += int(digit)
        total += val
print(total)
