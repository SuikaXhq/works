#include<iostream>
using namespace std;
bool find(int, int[], int , int);//查找数组中是否含有某数字

const int arrSize = 20;

int main() {
	int arr[arrSize] = {};
	int counter = 0;//输入数
	int index = 0;//合法元素末索引
	while (counter < 20) {
		int temp = 0;
		cout << "Type in a 10-100 number(inclusive) (" << counter + 1 << " of 20) : ";
		cin >> temp;
		
		//输入检查
		if (temp < 10 || temp > 100) {
			cout << "Illegal Input!" << endl;
			continue;

		} else {

			if (counter == 0) {//首项录入
				arr[index] = temp;
				index++;
			} else {//后续项录入
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