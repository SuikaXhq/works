#include <iostream>
#include <iomanip>
#include "9.7_Time.h"
using namespace std;

Time::Time(int hour, int minute, int second) {
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}

void Time::setHour(int h) {
	if (h >= 0 && h < 24) {
		_hour = h;
	} else {
		_hour = 0;
	}
}
void Time::setMinute(int m) {
	if (m >= 0 && m <= 59) {
		_minute = m;
	} else {
		_minute = 0;
	}
}
void Time::setSecond(int s) {
	if (s >= 0 && s <= 59) {
		_second = s;
	} else {
		_second = 0;
	}
}

int Time::getHour() const{
	return _hour;
}
int Time::getMinute() const{
	return _minute;
}
int Time::getSecond() const{
	return _second;
}

void Time::printUniversal() const{
	cout << setw(2) << setfill('0') << getHour() << ':' << setw(2) << getMinute() << ':' << setw(2) << getSecond();
}
void Time::printStandard() const{
	cout << setw(2) << (getHour() == 0 || getHour() == 12 ? 12 : getHour() % 12) << ':' << setw(2) << setfill('0') << getMinute() << ':' << setw(2) << getSecond() << (getHour() < 12 ? "AM" : "PM");
}

void Time::tick() {
	if (getSecond() < 59) {
		setSecond(getSecond() + 1);
		return;
	}
	setSecond(0);
	if (getMinute() < 59) {
		setMinute(getMinute() + 1);
		return;
	}
	setMinute(0);
	if (getHour() < 23) {
		setHour(getHour() + 1);
		return;
	}
	setHour(0);
}

void tick(Time& time) {
	if (time._second < 59) {
		time._second++;
		return;
	}
	time._second = 0;
	if (time._minute < 59) {
		time._minute++;
		return;
	}
	time._minute = 0;
	if (time._hour < 23) {
		time._hour++;
		return;
	}
	time._hour = 0;
}
