//tester.cpp
#include "Invoice.h"
#include <iostream>
using namespace std;

int main() {
	Invoice invoice{"001", "RTX2080Ti", 150, 9999};
	cout << "The part number is " << invoice.getPartNumber()<<endl;
	cout << "The part description is " << invoice.getPartDescription() << endl;
	cout << "The quantity is " << invoice.getQuantity() << endl;
	cout << "The price is " << invoice.getPrice() << endl;
	cout << "The amount is " << invoice.getInvoiceAmount() << endl;
	system("pause");
}
//end tester.cpp