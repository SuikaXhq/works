#ifndef BIGINT_H
#define BIGINT_H
class BigInt {
	char* _data;
	int _bits;  //ʮ������λ��
	BigInt(char*, int);
public:
	BigInt(char*);
	BigInt();
	friend BigInt operator+(const BigInt& int1, const BigInt& int2) {return add(int1, int2);}
	static BigInt add(const BigInt& int1, const BigInt& int2) {
		BigInt bigInt;
		BigInt smallInt;
		if (int1._bits > int2._bits) {  //�ж�λ����С
			bigInt = int1;
			smallInt = int2;
		} else {
			bigInt = int2;
			smallInt = int1;
		}
		int newBits = bigInt._bits;
		char* newIntData = new char[bigInt._bits]();
		for (int i = 0; i < smallInt._bits; i++) {  //�Ӹ�λ��ʼѭ�����
			char temp = bigInt._data[i] + smallInt._data[i] - 48;    //char���͵ĺ�
			if (temp > '9') {   //��λ
				temp -= 10;
				if (i != bigInt._bits-1) {
					bigInt._data[i+1]++;
				} else {    //��λ��λ
					char* expandData = new char[bigInt._bits+1]();
					for (int j = 0; j < bigInt._bits; j++) {
						expandData[j] = newIntData[j];
					}
					delete newIntData;
					newIntData = expandData;
					newIntData[bigInt._bits] = '1';
					newBits++;
				}
			}
			newIntData[i] = temp;
		}
		if (smallInt._bits != bigInt._bits) {   //����ʣ��λ��
			for (int i = smallInt._bits; i < bigInt._bits; i++) {
				newIntData[i] = bigInt._data[i];
			}
		}
		return BigInt(newIntData, newBits);
	}
	char* toString();
	~BigInt();
};
#endif
