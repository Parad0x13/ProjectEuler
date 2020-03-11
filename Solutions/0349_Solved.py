# Project Euler problem 349 started 09Oct13 and solved 1505KST 25Nov13
# I know that 10^18 iterations is impossible to compute by brute force and the answer is possible to acertain
# because at around 10000 iterations the ant breaks off into a highway that has a period of 104 and continues
# forever. I thought I could solve the equation by finding all black tiles up to an iteration, i, where:
# (10^18-i)%104 = 0. That would find the remainder of iterations that can be applied to the highway. I
# calculated this at first to be 11064, the answer then was 115384615384614953 but that was not correct
# I also tried other things, but they didn't work either

# I ended up solving it in the coolest possible way possible ever. My algorithm was to find an initial
# iteration value that left an iteration count which would divide 104 evenly. I chose 11064 and everything
# should have went alright. I put my answer into Project Euler and I got the evil red cross of incorrectness
# Then a new guy that works with me asked for me to explain my algorithm and as I was going over my logic
# he concluded it was sound as well and we were both scratching our heads to figure out why it wasn't working
# What possible thing did I leave out? Well we decided to review my code since he was new to C++ and as I was
# going over my function for finding the amount of black tiles before the highway started I noticed that a loop
# was checking <= instead of just <. I asked him to change my code and recompile and I got a value 1 less than
# what I tried as an answer. I though "How stupid would it be if this was the right answer?" so we plugged it
# into Project Euler and BAM! Green checkmark of beauty. I jumped up and ran around the room. The highest
# previous answer I had successfully answered was 123 so solving 349 was a huge success to me. So because of
# this question I looked intelligent to a new coworker and succeeded in inflating my ego just a little bit more

from Euler.Solution import Solution
import Euler.Math as EM

# Cheap way of doing things, not very elegant
def blackAfterIterations(iterations):
    maxX = maxY = 400
    antX = antY = maxX // 2
    antDirection = "U"
    grid = [[False for i in range(maxX)] for j in range(maxY)]

    for d in range(iterations):
        newStatus = newRotation = None
        if grid[antY][antX]:
            newStatus = False
            newRotation = "CCW"
        else:
            newStatus = True
            newRotation = "CW"

        grid[antY][antX] = newStatus

        if newRotation == "CW":
            if False: pass
            elif antDirection == "U": antDirection = "R"
            elif antDirection == "R": antDirection = "D"
            elif antDirection == "D": antDirection = "L"
            elif antDirection == "L": antDirection = "U"

        if newRotation == "CCW":
            if False: pass
            elif antDirection == "U": antDirection = "L"
            elif antDirection == "R": antDirection = "U"
            elif antDirection == "D": antDirection = "R"
            elif antDirection == "L": antDirection = "D"

        if antDirection == "U": antY += 1
        if antDirection == "D": antY -= 1
        if antDirection == "L": antX -= 1
        if antDirection == "R": antX += 1

    count = sum([sum(row) for row in grid])
    return count

def logic():
    maximum = 10 ** 18
    iterationsBeforeHighwayPeriod = 11064    # (10^18 - 11064) % 104 = 0
    highwayPeriodIntervals = (maximum - iterationsBeforeHighwayPeriod) // 104
    totalHighwayIterations = highwayPeriodIntervals * 104
    beforeHW_BWCount = blackAfterIterations(iterationsBeforeHighwayPeriod)
    # Found that every 104 iterations in the highway period leaves exactly 12 new black tiles
    HW_BWCount = highwayPeriodIntervals * 12
    total_BWCount = beforeHW_BWCount + HW_BWCount
    return total_BWCount

solution = Solution(value = 115384615384614952, placement = 894)
solution.logic = logic
solution.run()
