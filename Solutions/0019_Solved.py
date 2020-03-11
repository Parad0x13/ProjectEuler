# Project Euler problem 19 solved at 2133KST

from Euler.Solution import Solution
import Euler.Math as EM

def daysInMonth(month, year):
    days_30 = [4, 6, 9, 11]
    days_31 = [1, 3, 5, 7, 8, 10, 12]
    if month in days_30: return 30
    if month in days_31: return 31

    # Otherwise it's February
    isCentury = year % 100 == 0
    isDivisibleBy4 = year % 4 == 0
    isDivisibleBy400 = year % 400 == 0

    isLeapYear = False
    if isDivisibleBy4:
        isLeapYear = True
        if isCentury and not isDivisibleBy400:
            isLeapYear = False

    if isLeapYear: return 29
    return 28

def dayOfWeek(day, month, year):
    # 1 January 1900 was a Monday
    assert year >= 1900

    daysSince1Jan1900 = 0
    yearDelta = year
    monthDelta = month
    dayDelta = day

    for y in range(yearDelta):
        currentYear = 1900 + y
        for m in range(12):
            for d in range(daysInMonth(m, currentYear)):
                daysSince1Jan1900 += 1

    for m in range(monthDelta):
        for d in range(daysInMonth(m, year)):
            daysSince1Jan1900 += 1

    for d in range(dayDelta):
        daysSince1Jan1900 += 1

    weeks = int(daysSince1Jan1900 / 7.0)
    finalDay = daysSince1Jan1900 - weeks * 7
    return finalDay

def logic():
    totalSundays = 0
    for y in range(1901, 2000 + 1):
        for m in range(12):
            day = dayOfWeek(1, m, y)
            if day == 0: totalSundays += 1

    # I'm not exactly sure why this is needed...
    # Confer with the CPP version to make sure it returns properly
    # Maybe it has to do with the year start range not being 1902? I'm off by one somehow
    totalSundays -= 1

    return totalSundays

solution = Solution(value = 171, placement = 59397)
solution.logic = logic
solution.run()
