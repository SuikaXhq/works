#include <iostream>
#include <string>
using namespace std;
bool testPalindrome(string, int, int);

int main() {
	string str;
	while (cin) {
		getline(cin, str);
		cout << (testPalindrome(str, 0, str.length() - 1) ? "Palindrome!" : "Not a palindrome!") << endl;
	}
}

bool testPalindrome(string str, int startIndex, int endIndex) {
	//ÿ�μ����β2���ַ��Ƿ�һ��

	int temp1 = startIndex, temp2 = endIndex;

	//���Է���ĸ
//	while (!((str[temp1] >= 'a' && str[temp1] <= 'z') || (str[temp1] >= 'A' && str[temp1] <= 'Z')))
//		temp1++;
//	while (!((str[temp2] >= 'a' && str[temp2] <= 'z') || (str[temp2] >= 'A' && str[temp2] <= 'Z')))
//		temp2--;

	if (temp1 > temp2)//������ƶ��������м���ֹͣ
		return true;

	if (str[temp1] != str[temp2])//�ж���β�Ƿ���ͬ
		return false;
	else
		return testPalindrome(str, temp1 + 1, temp2 - 1);//���������һ����β�ַ�
}