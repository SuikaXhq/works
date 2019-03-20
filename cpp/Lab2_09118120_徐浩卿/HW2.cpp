#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#ifndef INTEGERSET_H
#define INTEGERSET_H
class IntegerSet {
	vector<bool> set;
	int validEntry(int x) const {
		return (x>=0 && x<=100);
	}
public:
	IntegerSet() : set(vector<bool>(101)){
		emptySet();
	}
	IntegerSet(int[], int);
	IntegerSet unionOfSets(const IntegerSet&);
	IntegerSet intersectionOfSets(const IntegerSet&);
	void emptySet();
	void inputSet();
	void insertElement(int);
	void deleteElement(int);
	void printSet() const;
	bool isEqualTo(const IntegerSet&) const;
};
#endif


IntegerSet::IntegerSet(int array[], int size) : set(vector<bool>(101)){
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

int main() {
	IntegerSet a;
	IntegerSet b;
	IntegerSet c;
	IntegerSet d;

	cout << "Enter set A:\n";
	a.inputSet();
	cout << "Enter set B:\n";
	b.inputSet();
	c = a.unionOfSets(b);
	d = a.intersectionOfSets(b);
	cout << "\nThe union of A and B is:\n";
	c.printSet();
	cout << "\nThe intersection of A and B is:\n";
	d.printSet();

	if (a.isEqualTo(b)) {
		cout << "Set A is equal to set B.\n";
	} else {
		cout << "Set A is not equal to set B.\n";
	}

	cout << "\nInserting 77 into set A...\n";
	a.insertElement(77);
	cout << "Set A is now:\n";
	a.printSet();

	cout << "\nDeleting 77 from set A...\n";
	a.deleteElement(77);
	cout << "Set A is now:\n";
	a.printSet();

	const int arraySize = 10;
	int intArray[arraySize] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1};
	IntegerSet e(intArray, arraySize);

	cout << "\nSet e is:\n";
	e.printSet();

	cout << endl;
}
