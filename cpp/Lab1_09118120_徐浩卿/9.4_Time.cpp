#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include "9.4_Time.h"
using namespace std;

Time::Time(int hour, int minute, int second) {
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}
Time::Time(const char* p) {
	if (strcmp(p, "current")) {
		Time();
		return;
	}
	int currentClock = time(0) % 86400 + 8*3600;  //86400 = 24*60*60, 东八区+8小时
	setHour(currentClock/3600); //3600 = 60*60
	currentClock %= 3600;
	setMinute(currentClock/60);
	setSecond(currentClock%60);
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
