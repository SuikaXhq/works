#include "BigInt.h"

BigInt::BigInt(char* input) {
	int n = 0;  //�ݴ�����λ��
	while(*input) {
		n++;
		input++;
	}   //��¼λ��
	_bits = n;
	_data = new char[n];
	for (int i = 0; i < n; i++) {
		input--;
		_data[i] = *input;
	}   //����洢����
}
BigInt::BigInt() {
	_bits = 1;
	_data = new char[1];
	_data[0] = '0';
}
BigInt::BigInt(char* data, int bits) {
	_bits = bits;
	_data = data;
}

char* BigInt::toString() {
	char* output = new char[_bits + 1];
	for (int i = 0; i < _bits; i++) {
		output[i] = _data[_bits-1-i];
	}
	output[_bits] = '\0';
	return output;
}

BigInt::~BigInt() {
	delete _data;
}
