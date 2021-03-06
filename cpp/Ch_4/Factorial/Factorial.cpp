// Factorial.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char mode;//mode identifier
	double x;//input variable
	int number;//number for (a)
	int accuracy;
	double answer;//output
	int temp;
	double tempx;//temp variable for x
	cout << "Enter a character ('a' to print factorial, 'b' to estimate e, 'c' to compute e^x, 'd' to end): ";
	while (cin >> mode) {
		switch (mode)
		{
		case 'a'://a) prints factorial
			cout << "Enter a number: ";
			cin >> number;

			//Input Check
			if (number < 0) {
				cout << "Illegal input!\n";
				break;
			}

			//Calculate
			answer = 1;
			for (int i = 1; i <= number; i++)
				answer *= i;
			cout << "The factorial of " << number << " is " << fixed << setprecision(0) << answer;
			break;

		case 'b'://b) estimates e
			cout << "Enter a number for accuracy: ";
			cin >> accuracy;

			//Input Check
			if (accuracy <= 0) {
				cout << "Illegal input!\n";
				break;
			}

			//Calculate
			answer = 1;//e = 1 when accuracy = 1
			temp = 1;
			for (int i = 1; i < accuracy; i++) {
				temp *= i;
				answer += 1.0 / temp;
			}
			cout << "e = " << fixed << setprecision(10) << answer;
			break;

		case 'c'://c) computes e^x
			cout << "Enter a number for accuracy: ";
			cin >> accuracy;

			//Input Check
			if (accuracy <= 0) {
				cout << "Illegal input!\n";
				break;
			}

			cout << "Enter x: ";
			cin >> x;

			//Input Check
			if (x <= 0) {
				cout << "Illegal input!\n";
				break;
			}

			//Calculate
			answer = 1;//e^x = 1 when accuracy = 1
			temp = 1;
			tempx = 1;
			for (int i = 1; i < accuracy; i++) {
				temp *= i;
				tempx *= x;
				answer += tempx / temp;
			}
			cout << "e^x = " << fixed << setprecision(10) << answer;
			break;

		case 'd'://end
			return 0;

		default:
			cout << "Illegal input!";
		}
		cout << "\n\nEnter a character ('a' to print factorial, 'b' to estimate e, 'c' to compute e^x, 'd' to end): ";
	}
}