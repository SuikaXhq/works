/**
 *  Last modified: 2019/3/26
 */

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
using namespace std;
#define LBRACKET 32767

string parseToPostfix(const string&);  //Infix -> Postfix
double parseToDouble(const string&);   //Postfix -> Double
double evaluateInfix(const string&);    //Infix -> Double

double getResult(double, double, char); //计算单个运算得到的答案
short priority(char);   //操作符优先级, 0代表非符号
short isMatch(char,char);    //判断括号是否匹配

int main() {
	string test = "6 - 5 * ( 1 + 4 ) / 2";
	cout << '>' << test << endl;
	cout << "Postfix: " << parseToPostfix(test) << endl;
	cout << "Postfix to answer: "<< parseToDouble(parseToPostfix(test)) << endl;
	cout << "Infix to answer: " << evaluateInfix(test) << endl;
	cout << endl;
	
	cout << "Type in an expression: " << endl;
	while (cin) {
		cout << '>';
		getline(cin, test);
		cout << "Postfix: " << parseToPostfix(test) << endl;
		cout << "Postfix to answer: "<< parseToDouble(parseToPostfix(test)) << endl;
		cout << "Infix to answer: " << evaluateInfix(test) << endl;
		cout << endl;
	}
}

string parseToPostfix(const string& infix) {
	string postfix;	//result
	stack<char> s;    //operator stack
	int size = infix.size();

	for (int i = 0; i < size; ++i) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix.append(1,infix[i]);
			postfix.append(1,' ');
			continue;
		}
		
		if (priority(infix[i]) == 0)continue;
		
		if (priority(infix[i]) > 0) {   //+ - * / ( {

			while (!s.empty() && priority(s.top()) != LBRACKET && priority(infix[i]) <= priority(s.top())) {
				postfix.append(1, s.top());
				postfix.append(1,' ');
				s.pop();
			}
			s.push(infix[i]);

		} else {    //处理右括号情况

			while (!s.empty() && isMatch(s.top(), infix[i]) == 1) {
				postfix.append(1, s.top());
				postfix.append(1,' ');
				s.pop();
			}
			s.pop();    //pop掉左括号

		}
	}   //End for

	while (!s.empty()) {
		postfix.append(1, s.top());
		postfix.append(1,' ');
		s.pop();
	}

	return postfix;
}

double parseToDouble(const string& postfix) {
	stack<double> s;
	int size = postfix.size();

	for (int i = 0; i < size; ++i) {
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			s.push(postfix[i] - '0');
			continue;
		}
		if (priority(postfix[i]) == 0)continue;
		if (priority(postfix[i])) {	//postfix中没有括号，不用考虑
			double temp2 = s.top();
			s.pop();
			double temp1 = s.top();
			s.pop();
			s.push(getResult(temp1, temp2, postfix[i]));
			continue;
		}
	}   //End for

	return s.top();
}

double evaluateInfix(const string& infix) {
	stack<double> ns;   //number stack
	stack<char> os;    //operator stack
	int size = infix.size();

	for (int i = 0; i < size; ++i) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			ns.push(infix[i] - '0');
		}
		if (priority(infix[i]) == 0)continue;
		if (priority(infix[i]) > 0) {   //+ - * / ( {
			while (!os.empty() && priority(os.top()) != LBRACKET && priority(infix[i]) <= priority(os.top())) {
				double temp2 = ns.top();
				ns.pop();
				double temp1 = ns.top();
				ns.pop();
				ns.push(getResult(temp1, temp2, os.top()));
				os.pop();
			}
			os.push(infix[i]);
		} else {    //处理右括号情况
			while (!os.empty() && isMatch(os.top(), infix[i]) == 1) {
				double temp2 = ns.top();
				ns.pop();
				double temp1 = ns.top();
				ns.pop();
				ns.push(getResult(temp1, temp2, os.top()));
				os.pop();
			}
			os.pop();    //pop掉左括号
		}
	}
	
	while (!os.empty()) {
		double temp2 = ns.top();
		ns.pop();
		double temp1 = ns.top();
		ns.pop();
		ns.push(getResult(temp1, temp2, os.top()));
		os.pop();
	}
	
	return ns.top();
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
		return 0;   //非符号
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
