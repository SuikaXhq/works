/**
 *  Last modified: 2019/3/26
 */

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
using namespace std;
#define LBRACKET 32767

double evaluateInfix(const string&);    //Infix -> Double

void bracketError(int = -1);    //抛出括号错误，参数为错误位置
void symbolError(int = -1); //抛出操作符错误，参数为错误位置

double getResult(double, double, char); //计算单个运算得到的答案
void operate(stack<double>&, char);    //将stack顶的2个元素按op运算后压入
short priority(char);   //操作符优先级
short isMatch(char,char);    //判断括号是否匹配

int main() {
	string test = "6.1*(.23-1)+4/-2";
	cout << "Type in any expression to evaluate:" << endl;
	cout << "\nExample:" << endl;
	cout << '>' << test << endl;
	cout << '=' << evaluateInfix(test) << endl;
	cout << endl;
	while (cin) {
		cout << '>';
		getline(cin, test);
		cout << '=' << evaluateInfix(test) << endl;
		cout << endl;
	}
}

double evaluateInfix(const string& infix) {
	stack<double> ns;   //number stack
	stack<char> os; //operator stack
	int size = infix.size();
	char preItem = '\0';	//previous item('\0' = head of expression, '0' = number, '+' = operator)
	unsigned int bracketCount = 0;  //check if missing rbracket
	
	for (int i = 0; i < size; ++i) {
		
		if (infix[i] == ' ')continue;

		if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {

			if (preItem == '0') {    //数字前不能是数字
				symbolError(i+1);
				return 0;
			}

			//解析数字
			double temp = 0.0;
			--i;

			while (infix[i+1] >= '0' && infix[i+1] <= '9') {
				temp *= 10;
				temp += infix[i+1] - '0';
				++i;
			}

			if (infix[i+1] == '.') {
				++i;
				double base = 0.1;
				while (infix[i+1] >= '0' && infix[i+1] <= '9') {
					temp += base * (infix[i+1] - '0');
					base /= 10;
					++i;
				}
			}

			ns.push(temp);
			preItem = '0';
			continue;

		}
		
		if (priority(infix[i]) == 0) {
			//非法字符
			cout << "Illegal character at " << i+1 << "." << endl;
			return 0;
		}
		
		if (priority(infix[i]) == 1) {  //处理+, -
			if (preItem != '0') {   //allow expression like -1 or --1
				ns.push(0);
			} else {
				while (!os.empty() && priority(os.top()) != LBRACKET) {
					operate(ns, os.top());
					os.pop();
				}
			}
			os.push(infix[i]);
			preItem = '+';
			continue;
		}
		
		if (priority(infix[i]) == LBRACKET) {   //处理(, {
			if (preItem == '0') {    //括号整体看作一个数字，前不能是数字
				symbolError(i+1);
				return 0;
			}
			os.push(infix[i]);
			preItem = '\0';
			++bracketCount;
			continue;
		}
		
		if (preItem != '0') {   //*, /, ), }前必须是数字
			symbolError(i+1);
			return 0;
		}
			
		if (priority(infix[i]) > 0) {   //处理*, /
		
			while (!os.empty() && priority(os.top()) != LBRACKET && priority(infix[i]) <= priority(os.top())) {
				operate(ns, os.top());
				os.pop();
			}
			os.push(infix[i]);
			preItem = '+';
			
		} else {    //处理右括号情况

			while (!os.empty() && isMatch(os.top(), infix[i]) == 1) {
				operate(ns, os.top());
				os.pop();
			}
			if (os.empty() || isMatch(os.top(), infix[i]) == -1) {
				bracketError(i+1);
				return 0;
			}
			os.pop();    //pop掉左括号
			preItem = '0';  //括号整体看作一个数字
			--bracketCount;
		}
	}
	
	if (preItem != '0') {   //末尾只能是数字
		symbolError(infix.size());
		return 0;
	}
	
	if (bracketCount != 0) {
		bracketError();
		return 0;
	} else {
		while (!os.empty()) {
			operate(ns, os.top());
			os.pop();
		}
	}

	return ns.top();
}

void bracketError(int index) {
	cout << "Illegal use of brackets.";
	if (index != -1) {
		cout << "(At " << index << ")";
	}
	cout << endl;
}

void symbolError(int index) {
	cout << "Illegal use of symbol.";
	if (index != -1) {
		cout << "(At " << index << ")";
	}
	cout << endl;
}

double getResult(double n1, double n2, char op) {
	switch (op) {

	case '+':
		return n1+n2;

	case '-':
		return n1-n2;

	case '*':
		return n1*n2;

	case '/':
		return n1/n2;
	}
}

void operate(stack<double>& s, char op) {
	double temp2 = s.top();
	s.pop();
	double temp1 = s.top();
	s.pop();
	s.push(getResult(temp1, temp2, op));
}

short priority(char c) {
	switch (c) {
 		
 	case '+': case '-':
 		return 1;

	case '*': case '/':
		return 2;

	case '(': case '{':
		return 32767;
		
	case ')':
		return -1;  //右括号优先级为负

	case '}':
		return -2;
		
	default:
		return 0;	//非法符号 
	}
}

short isMatch(char left, char right) {  //匹配返回0，错误匹配返回-1，left非括号返回1
	switch (left) {
	case '(':
		if (right == ')')
			return 0;
		else
			return -1;
		
	case '{':
		if (right == '}')
			return 0;
		else
			return -1;
			
	default:
		return 1;
	}
}
