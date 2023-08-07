from Euler.Solution import Solution
import Euler.Math as EM

# Farey sequences will produce all reduced fractions between two fractions
# I found this sequence on a Stand Up Maths video: https://www.youtube.com/watch?v=7LKy3lrkTRA
# https://en.wikipedia.org/wiki/Farey_sequence

def logic():
    d = 8
    fractions = []
    # Here we calculate the entire Farey Sequence then omit the first and last values
    #fractions.append((1, d))
    #fractions.append((d - 1, d))
    fractions.append((0, d))
    fractions.append((d, d))

    index = 0

    while True:
        a = fractions[index]
        b = fractions[index + 1]
        print(a, b)
        c = (a[0] + b[0], a[1] + b[1])
        gcd = EM.GCD(c[0], c[1])
        c = (c[0] // gcd, c[1] // gcd)

        if c[1] > d:    # In the event that we no longer have a correct denominator we continue
            index += 1
            print("greater?")
            continue

        fractions.insert(index + 1, c)

        print(fractions)
        print(index)
        if index == 2: break

solution = Solution(value = None, placement = None)
solution.logic = logic
solution.run()
