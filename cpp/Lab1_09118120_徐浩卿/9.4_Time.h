#ifndef TIME_H
#define TIME_H
class Time {
	int _hour;
	int _minute;
	int _second;
public:
	Time(int = 0, int = 0, int = 0);
	Time(const char*);

	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	void printUniversal() const;
	void printStandard() const;
};
#endif
