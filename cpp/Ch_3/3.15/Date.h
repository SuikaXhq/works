//Date.h
class Date
{
public:
	Date(int, int, int);
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	int getYear();
	int getMonth();
	int getDay();
	void displayDate();
private:
	int year_;
	int month_;
	int day_;
};
//end Date.h
