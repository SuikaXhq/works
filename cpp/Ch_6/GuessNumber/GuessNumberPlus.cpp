#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Status {HIGH, LOW, CORRECT, CONTINUE, EXIT};
/*
 *HIGH: ������̫��
 *LOW: ������̫��
 *CORRECT: �²���ȷ
 *CONTINUE: ������Ϸ���
 *EXIT: �˳���Ϸ���
 */

Status check(int, int);

int main() {
	int target;//Ŀ������
	int input;//�û�����
	char sign;//y/n����
	int times;//�²����
	Status currentStatus = CONTINUE;//��ǰ��Ϸ״̬
	while (cin) {
		times = 0;//��ʼ���²����
		if (currentStatus == EXIT)//���ΪEXITʱ�˳���Ϸ
			break;

		srand(time(0));
		target = 1 + rand() % 1000;//���������
		cout << "I have a number between 1 to 1000.\nCan you guess my number?\nPlease type your first guess.\n";
		while (currentStatus != CORRECT) {
			cin >> input;
			times++;
			currentStatus = check(input, target);
			switch (currentStatus) {
			case HIGH:
				cout << "Too high! Try again.\n";
				break;
			case LOW:
				cout << "Too low! Try again.\n";
				break;
			case CORRECT:
				cout << "Excellent! You guess the number.\n";
				
				break;
			}
		}

		//����
		cout << "\nYou guessed " << times << " times.\n";
		if (times > 10)
			cout << "You should be able to do better.\n";
		else if (times < 10)
			cout << "Either you know the secret or you got lucky!\n";
		else
			cout << "Ahah! You know the secret!\n";
		cout << "Would you want to play again ? (y or n)\n";
		
		cin >> sign;//��ȡy/n����
		if (sign == 'y')
			currentStatus = CONTINUE;
		else if (sign == 'n')
			currentStatus = EXIT;
		else
			/*�Ƿ����봦��*/
			break;
	}
}

Status check(int input, int target) {
	if (input > target)
		return HIGH;
	else if (input < target)
		return LOW;

	return CORRECT;
}