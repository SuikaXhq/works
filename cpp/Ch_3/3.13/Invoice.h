//Invoice.h
#include <string>
using namespace std;

class Invoice
{
public:
	Invoice(string, string, int, int);
	void setPartNumber(string);
	void setPartDescription(string);
	void setQuantity(int);
	void setPrice(int);
	string getPartNumber();
	string getPartDescription();
	int getQuantity();
	int getPrice();
	int getInvoiceAmount();
private:
	string partNumber_;
	string partDescription_;
	int quantity_;
	int price_;
};
//end Invoice.h