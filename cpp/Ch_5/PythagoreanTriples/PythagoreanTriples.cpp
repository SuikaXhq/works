// PythagoreanTriples.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "side1\tside2\thypotenuse\n";
	for (int a = 1; a <= 500; a++)
		for (int b = 1; b <= 500; b++)
			for (int c = 1; c <= 500; c++)
				if (c * c == a * a + b * b)//c为斜边
					cout << a << "\t" << b << "\t" << c << endl;
}