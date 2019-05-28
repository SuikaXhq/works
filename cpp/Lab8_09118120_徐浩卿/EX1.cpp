#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;

void storeNumbers();
void output();


int main() {
	
	cout << "Input some numbers (input Ctrl+Z to end): ";
	storeNumbers();
	
	output();
	cout << "\nThe result has been output into \"output.txt\"." << endl;
	
}


void storeNumbers() {

	unsigned temp;
	
	ofstream output("numbers.txt", ios::out);
	
	if (!output) {          										// confirm that file is available
		cerr << "File \"numbers.txt\" couldn't be opened." << endl;
		exit(1);
	}
	
	while (cin >> temp) {           // create "numbers.txt"
		output << temp << ' ';
	}
	
	output.close();
	
}

void output() {
	
	unsigned list[64] = {};
	unsigned temp;
	
	ifstream input("numbers.txt", ios::in);
	ofstream output("output.txt", ios::out);
	
	if (!input || !output) {										// confirm that files are available
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	
	while (input >> temp) {         // read the numbers for "numbers.txt"
		++list[temp];
	}
	
	input.close();
	
	for (int i = 1; i < 64; ++i) {  // create "output.txt"
		if (list[i] == 0) {
			continue;
		}
		output << "Number of " << i << " responses: " << list[i] << endl;
	}
	
	output.close();
	
}
