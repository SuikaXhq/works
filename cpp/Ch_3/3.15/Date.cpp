//Date.cpp
#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int month, int day, int year) {
	setMonth(month);
	setDay(day);
	setYear(year);
}

void Date::setYear(int year) {
	year_ = year;
}
void Date::setMonth(int month) {
	if (month >= 1 && month <= 12)
		month_ = month;
	else
		month_ = 1;
}
void Date::setDay(int day) {
	day_ = day;
}

int Date::getYear() {
	return year_;
}
int Date::getMonth() {
	return month_;
}
int Date::getDay() {
	return day_;
}
void Date::displayDate() {
	cout << "The Date is " << getMonth() << '/' << getDay() << '/' << getYear() << endl;
}
//end Date.cpp