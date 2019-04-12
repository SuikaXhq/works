#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
using namespace std;


/************************************** Class Array **************************************/
///////////////////////////////////////////////////////////////////////////////////////////

template <class T, int n>
class Array {
	
	int size;
	T* dataArr;

public:
	Array();
	Array(const Array<T,n>&);
	~Array();
	int getSize() const;
	
	//operator overload
	const Array<T,n>& operator=(const Array<T,n>&);
	T& operator[](int);
	T operator[](int) const;    //for const Arrays
	bool operator==(const Array<T,n>&) const;
	bool operator!=(const Array<T,n>& rightArr) const {
		return !(*this == rightArr);
	}
	
	//friend operator functions overload
	template <class C, int m>
	friend istream& operator>>(istream&, Array<C,m>&);
	template <class C, int m>
	friend ostream& operator<<(ostream&, const Array<C,m>&);
};




//constructors & destructor
template <class T, int n>
Array<T,n>::Array() {
	if (n > 0) {
		size = n;
	} else {
		throw invalid_argument("Size must be > 0");
	}
	dataArr = new T[size];
}
template <class T, int n>
Array<T,n>::Array(const Array<T,n>& oldArray) : size(oldArray.size) {
	dataArr = new T[size];
	
	for (int i = 0; i < size; ++i) {
		dataArr[i] = oldArray.dataArr[i];
	}
}
template <class T, int n>
Array<T,n>::~Array() {
	delete[] dataArr;
}



//get size
template <class T, int n>
int Array<T,n>::getSize() const {
	return size;
}




//operator overload
template <class T, int n>
const Array<T,n>& Array<T,n>::operator=(const Array<T,n>& oldArray) {
	if (&oldArray != this) {
		for (int i = 0; i < size; ++i) {
			dataArr[i] = oldArray.dataArr[i];
		}
	}
	
	return *this;
}


template <class T, int n>
T& Array<T,n>::operator[](int index) {
	if (index < 0 || index >= size) {
		throw out_of_range("Subscript out of range.");
	} else {
		return dataArr[index];
	}
}



template <class T, int n>
T Array<T,n>::operator[](int index) const {     // for const Arrays
	if (index < 0 || index >= size) {
		throw out_of_range("Subscript out of range.");
	} else {
		return dataArr[index];
	}
}


template <class T, int n>
bool Array<T,n>::operator==(const Array<T,n>& rightArr) const {
	for (int i = 0; i < size; ++i) {
		if (dataArr[i] != rightArr.dataArr[i]) {
			return false;
		}
	}
	
	return true;
}




//friend operator functions
template <class T, int n>
istream& operator>>(istream& input, Array<T,n>& arr) {
	for (int i = 0; i < arr.size; ++i) {
		input >> arr.dataArr[i];
	}
	return input;
}


template <class T, int n>
ostream& operator<<(ostream& output, const Array<T,n>& arr) {
	for (int i = 0; i < arr.size; ++i) {
		output << arr.dataArr[i] << ' ';
	}
	return output;
}

///////////////////////////////////////////////////////////////////////////////////////////
/************************************** Class Array **************************************/





int main() {
	Array<int, 5> intArray;
	Array<string, 7> stringArray;
	
	cout << "Enter 5 ints: " << endl;
	cin >> intArray;
	cout << "\nThe values in the intArray are: " << endl;
	cout << intArray << endl;
	
	cout << "\nEnter 7 words: " << endl;
	cin >> stringArray;
	cout << "\nThe values in the stringArray are: " << endl;
	cout << stringArray << endl;
}
