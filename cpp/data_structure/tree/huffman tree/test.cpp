#include <iostream>
#include "SortedQueue.h"
using namespace std;

int main() {
	SortedQueue<char> sq;
	sq.push('A', 1);
	sq.push('B', 4);
	sq.push('C', 2);
	sq.push('D', 1);
	sq.push('E', 2);
	sq.push('F', 3);
	
	char temp;
	while (!sq.empty()) {
		sq.pop(temp);
		cout << temp << ' ';
	}
}
