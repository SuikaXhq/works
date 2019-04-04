#include <iostream>
#include <string>
#include "List.h"
#include "List.cpp"
using namespace std;

int main() {
	List<string> routeList;
	routeList.add("Panchi Wharf");
	routeList.add("Bai Lu Zhou Cultural Them Park");
	routeList.add("Dong Shui Guan");
	routeList.add("Qi Cai Shui Jie");
	routeList.add("Panchi Pier");
    cout << "The original route is\n";
	routeList.print();
	
	cout << "\nAfter inserting Zhong Hua Men:\n";
	routeList.insert("Zhong Hua Men", 4);
	routeList.print();
	
	cout << "\nThe forward spot of Qi Cai Shui Jie is " << routeList.find("Qi Cai Shui Jie", "forward");
	cout << "\nThe backward spot of Dong Shui Guan is " << routeList.find("Dong Shui Guan", "backward");
}
