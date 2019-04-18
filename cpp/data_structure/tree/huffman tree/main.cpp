#include <iostream>
#include "Huffman.h"
using namespace std;


/******************** main ******************/

int main() {
	
	string test = "choose me let me make you happy";
	char alphabet[] = {'c','s','l','t','k','u','h','a','y','p','o','m','e',' '};
	int weights[] = {1,1,1,1,1,1,2,2,2,2,3,3,5,6};
	
	
	cout << "Original string: \n\"" << test << '\"' << endl;
	cout << "\nHuffman code: " << endl;
	huffmanCode(alphabet, weights, 14);
	
	string binCode = encoder(test, alphabet, weights, 14);
	cout << "\nBin code: \n" << binCode << endl;
	cout << "\nTransform into characters: \n\"" << decoder(binCode, huffmanTree(alphabet, weights, 14)) << '\"' << endl;
	
}


/******************** main ******************/







