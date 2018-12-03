//Invoice.cpp
#include "Invoice.h"
using namespace std;


Invoice::Invoice(string partNumber, string partDescription, int quantity, int price) {
	setPartNumber(partNumber);
	setPartDescription(partDescription);
	setQuantity(quantity);
	setPrice(price);
}

void Invoice::setPartNumber(string partNumber) {
	partNumber_ = partNumber;
}
void Invoice::setPartDescription(string partDescription) {
	partDescription_ = partDescription;
}
void Invoice::setQuantity(int quantity) {
	if (quantity >= 0)
		quantity_ = quantity;
	else
		quantity_ = 0;
}
void Invoice::setPrice(int price) {
	if (price >= 0)
		price_ = price;
	else
		price_ = 0;
}

string Invoice::getPartNumber() {
	return partNumber_;
}
string Invoice::getPartDescription() {
	return partDescription_;
}
int Invoice::getQuantity() {
	return quantity_;
}
int Invoice::getPrice() {
	return price_;
}
int Invoice::getInvoiceAmount() {
	return quantity_ * price_;
}
//end Invoice.cpp