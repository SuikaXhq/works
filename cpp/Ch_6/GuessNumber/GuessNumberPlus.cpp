#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Status {HIGH, LOW, CORRECT, CONTINUE, EXIT};
/*
 *HIGH: 所猜数太高
 *LOW: 所猜数太低
 *CORRECT: 猜测正确
 *CONTINUE: 继续游戏标记
 *EXIT: 退出游戏标记
 */

Status check(int, int);

int main() {
	int target;//目标数字
	int input;//用户猜数
	char sign;//y/n输入
	int times;//猜测次数
	Status currentStatus = CONTINUE;//当前游戏状态
	while (cin) {
		times = 0;//初始化猜测次数
		if (currentStatus == EXIT)//标记为EXIT时退出游戏
			break;

		srand(time(0));
		target = 1 + rand() % 1000;//构造待猜数
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

		//评价
		cout << "\nYou guessed " << times << " times.\n";
		if (times > 10)
			cout << "You should be able to do better.\n";
		else if (times < 10)
			cout << "Either you know the secret or you got lucky!\n";
		else
			cout << "Ahah! You know the secret!\n";
		cout << "Would you want to play again ? (y or n)\n";
		
		cin >> sign;//获取y/n输入
		if (sign == 'y')
			currentStatus = CONTINUE;
		else if (sign == 'n')
			currentStatus = EXIT;
		else
			/*非法输入处理*/
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