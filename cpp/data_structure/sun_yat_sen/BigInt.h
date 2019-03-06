#ifndef BIGINT_H
#define BIGINT_H
class BigInt {
	char* _data;
	int _bits;  //十进制下位数
	BigInt(char*, int);
public:
	BigInt(char*);
	BigInt();
	friend BigInt operator+(const BigInt& int1, const BigInt& int2) {return add(int1, int2);}
	static BigInt add(const BigInt& int1, const BigInt& int2) {
		BigInt bigInt;
		BigInt smallInt;
		if (int1._bits > int2._bits) {  //判断位数大小
			bigInt = int1;
			smallInt = int2;
		} else {
			bigInt = int2;
			smallInt = int1;
		}
		int newBits = bigInt._bits;
		char* newIntData = new char[bigInt._bits]();
		for (int i = 0; i < smallInt._bits; i++) {  //从个位开始循环求和
			char temp = bigInt._data[i] + smallInt._data[i] - 48;    //char类型的和
			if (temp > '9') {   //进位
				temp -= 10;
				if (i != bigInt._bits-1) {
					bigInt._data[i+1]++;
				} else {    //首位进位
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
		if (smallInt._bits != bigInt._bits) {   //补齐剩余位数
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
