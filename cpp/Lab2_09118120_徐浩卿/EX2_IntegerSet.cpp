#include <iostream>
#include <iomanip>
#include "EX2_IntegerSet.h"
using namespace std;

IntegerSet::IntegerSet(int array[], int size) {
	emptySet();
	for(int i = 0; i < size; i++) {
		insertElement(array[i]);
	}
}
IntegerSet IntegerSet::unionOfSets(const IntegerSet& r) {
	IntegerSet temp;
	for (int i = 0; i < 101; i++) {
		temp.set[i] = set[i] | r.set[i];
	}
	return temp;
}
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& r) {
	IntegerSet temp;
	for (int i = 0; i < 101; i++) {
		temp.set[i] = set[i] & r.set[i];
	}
	return temp;
}
void IntegerSet::emptySet() {
	for (int i = 0; i < 101; i++) {
		set[i] = 0;
	}
}
void IntegerSet::inputSet() {
	int number;
	do {
		cout << "Enter an element (-1 to end): ";
		cin >> number;
		if (validEntry(number)) {
			set[number] = 1;
		} else if (number != -1) {
			cerr << "Invalid Element.\n";
		}
	} while (number != -1);
	cout << "Entry complete." << endl;
}
void IntegerSet::insertElement(int k) {
	if (validEntry(k)) {
		set[k] = 1;
	} else {
		cerr << "Invalid insert attempted.\n";
	}
}
void IntegerSet::deleteElement(int k) {
	if (validEntry(k)) {
		set[k] = 0;
	} else {
		cerr << "Invalid delete attempted.\n";
	}
}
void IntegerSet::printSet() const {
	int x = 1;
	bool empty = false;
	cout << '{';
	
	for (int u = 0; u < 101; u++) {
		if (set[u]) {
			cout << setw(4) << u << (x%10 == 0 ? "\n" : "");
			empty = false;
			x++;
		}
	}
	
	if (empty) {
		cout << setw(4) << "---";
	}
	
	cout << setw(4) << '}' << endl;
}
bool IntegerSet::isEqualTo(const IntegerSet& r) const{
	for (int i = 0; i < 101; i++){
		if (set[i] != r.set[i]) {
			return false;
		}
	}
	return true;
}
