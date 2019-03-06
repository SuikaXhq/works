#include <iostream>
#include "BigInt.h"
using namespace std;

int main() {
	BigInt int1("123456789043625654273454545454563456123456789043625654273454545454563456123456789043625654273454545454563456123456789043625654273454545454545456345612345678904362565427345454545454545634561234567890436256542734545454545454563456123456789043625654273454545454545456345612345678904362565427345454545454545634561234567890436256542734545454545454563456123456789043625654273454545454563456");
	BigInt int2("234567890122257245725724572234567890122257245725724572234567890122257245725724572234567890122257245725724572234567890122257245725724572234567890122257245725724572223456789012225724572572457223456789012225724572572457223456789012225724572572457223456789012225724572572457223456789012225724572572457223456789012225724572572457");
	cout << int1.toString() << endl;
	cout << int2.toString() << endl;
	cout << (int1+int2).toString();
}
