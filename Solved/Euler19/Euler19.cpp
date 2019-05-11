// Project Euler problem 19 solved at 2133KST. I was the 59397th person to have solved this problem
#include <iostream>
#include <cmath>

using namespace std;

typedef enum {
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
}DAYS_OF_THE_WEEK;

typedef enum {
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
}MONTHS_OF_THE_YEAR;

int daysInMonth(int month, int year) {
	if(
	month == SEPTEMBER ||
	month == APRIL ||
	month == JUNE ||
	month == NOVEMBER) return 30;
	else if(
	month == JANUARY ||
	month == MARCH ||
	month == MAY ||
	month == JULY ||
	month == AUGUST ||
	month == OCTOBER ||
	month == DECEMBER) return 31;
	else if(month == FEBRUARY) {
		bool isCentury = year%100==0?true:false;
		bool isDivisibleBy4 = year%4==0?true:false;
		bool isDivisibleBy400 = year%400==0?true:false;
		bool isLeapYear = false;
		if(isDivisibleBy4) {
			isLeapYear = true;
			if(isCentury && !isDivisibleBy400)isLeapYear = false;
		}
		if(isLeapYear)return 29;
		return 28;
	}	
}

int dayOfWeek(int day, int month, int year) {
	// 1 January 1900 was a Monday
	if(year < 1900) {
		cout << "Sorry, cannot calculate prior to 1 January 1900 : (" << endl;
		return -1;
	}
	else {
		int daysSince1Jan1900 = 0;
		int yearDelta = year - 1900;
		int monthDelta = month - JANUARY;
		int dayDelta = day - SUNDAY;
		for(int y=0;y<yearDelta;y++) {
			int currentYear = 1900 + y;
			for(int m=0;m<12;m++) {
				for(int d=0;d<daysInMonth(m, currentYear);d++)
					daysSince1Jan1900++;
			}
		}
		for(int m=0;m<monthDelta;m++) {
			for(int d=0;d<daysInMonth(m, year);d++)
				daysSince1Jan1900++;
		}
		for(int d=0;d<dayDelta;d++)daysSince1Jan1900++;

		int weeks = floor(daysSince1Jan1900 / 7.0f);
		int finalDay = daysSince1Jan1900 - weeks*7;
	}
}

int main() {
	int totalSundays = 0;
	for(int y=1901;y<=2000;y++) {
		for(int m=0;m<12;m++) {
			int day = dayOfWeek(1, m, y);
			if(day == SUNDAY)totalSundays++;
		}
	}
	cout << totalSundays << endl;
	return false;
}
