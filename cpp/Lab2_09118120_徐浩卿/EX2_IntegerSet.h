#ifndef INTEGERSET_H
#define INTEGERSET_H
class IntegerSet {
	int set[101];
	int validEntry(int x) const {
		return (x>=0 && x<=100);
	}
public:
	IntegerSet(){
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
