#include<iostream>
using namespace std;
bool find(int, int[], int , int);//�����������Ƿ���ĳ����

const int arrSize = 20;

int main() {
	int arr[arrSize] = {};
	int counter = 0;//������
	int index = 0;//�Ϸ�Ԫ��ĩ����
	while (counter < 20) {
		int temp = 0;
		cout << "Type in a 10-100 number(inclusive) (" << counter + 1 << " of 20) : ";
		cin >> temp;
		
		//������
		if (temp < 10 || temp > 100) {
			cout << "Illegal Input!" << endl;
			continue;

		} else {

			if (counter == 0) {//����¼��
				arr[index] = temp;
				index++;
			} else {//������¼��
				if (!find(temp, arr, 0, counter - 1)) {
					arr[index] = temp;
					index++;
				}
			}
		}

		counter++;
	}
	
	for (int i = 0; i < index; i++)
		cout << arr[i] << ' ';
	
	system("pause");
}

bool find(int finding, int arr[], int start, int end) {
	if (arr[start] == finding)
		return true;
	if (start == end)
		return false;
	else
		return find(finding, arr, start + 1, end);
}