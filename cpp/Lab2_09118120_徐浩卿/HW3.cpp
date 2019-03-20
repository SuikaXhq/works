#ifndef EMERGENCY_H
#define EMERGENCY_H
#include <iostream>
#include <string>
using namespace std;
class Emergency {
	string nameOfCaller;
	string addressOfCaller;
	string addressOfEmergency;
	string reportTime;
	string phoneNumOfCaller;
	string natureOfEmergency;
	string appropriateResponders;
	string status;
public:
	Emergency();
	string getNameOfCaller() const;
	string getAddressOfCaller() const;
	string getAddressOfEmergency() const;
	string getReportTime() const;
	string getPhoneNumOfCaller() const;
	string getNatureOfEmergency() const;
	string getAppropriateResponders() const;
	string getStatus() const;
	void setNameOfCaller(string);
	void setAddressOfCaller(string);
	void setAddressOfEmergency(string);
	void setReportTime(string);
	void setPhoneNumOfCaller(string);
	void setNatureOfEmergency(string);
	void setAppropriateResponders(string);
	void setStatus(string);
};
#endif
