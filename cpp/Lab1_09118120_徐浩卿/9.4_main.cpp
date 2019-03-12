#include <iostream>
#include "9.4_Time.h"

int main() {
	Time currentTime("current");
	std::cout << "Current time is ";
	currentTime.printUniversal();
}
