#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
using namespace std;
#define LBRACKET 32767

string parseToPostfix(const string&);  //Infix -> Postfix
double parseToDouble(const string&);   //Postfix -> Double
double evaluateInfix(const string&);    //Infix -> Double

void bracketError(int = -1);    //�׳����Ŵ��󣬲���Ϊ����λ��
void symbolError(int = -1); //�׳����������󣬲���Ϊ����λ��

double getResult(double, double, char); //���㵥������õ��Ĵ�
void operate(stack<double>&, char);    //��stack����2��Ԫ�ذ�op�����ѹ��
short priority(char);   //���������ȼ�
bool isSymbol(char);    //�ж��Ƿ��ǲ�����
short isMatch(char,char);    //�ж������Ƿ�ƥ��

int main() {
	string test = "6.4-6*1.7+6/2";
	cout << parseToPostfix(test) << endl;
	cout << parseToDouble(parseToPostfix(test));
}

string parseToPostfix(const string& infix) {
	string postfix;	//result
	stack<char> s;    //operator stack
	int size = infix.size();
	
	for (int i = 0; i < size; ++i) {
		if (infix[i] == ' ')continue;
		if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
			postfix.append(1,infix[i]);
			if (i+1 >= size || infix[i+1] == ' ' || isSymbol(infix[i+1])) {
				postfix.append(1,' ');
			}
			continue;
		}
		
		if (priority(infix[i]) == 0) {	//�Ƿ��ַ� 
			cout << "Illegal character at " << i+1 << "." << endl; 
			break;
		}
		
		if (priority(infix[i]) > 0) {   //+ - * / ( {
		
			while (!s.empty() && priority(s.top()) != LBRACKET && priority(infix[i]) <= priority(s.top())) {
				postfix.append(1, s.top());
				postfix.append(1,' ');
				s.pop();
			}
			s.push(infix[i]);
			
		} else {    //�������������
		
			while (!s.empty() && isMatch(s.top(), infix[i]) == 1) {
				postfix.append(1, s.top());
				postfix.append(1,' ');
				s.pop();
			}
			if (s.empty() || isMatch(s.top(), infix[i]) == -1) {
				bracketError(i+1);
				break;
			}
			s.pop();    //pop��������
			
		}
	}   //End for
	
	while (!s.empty()) {
		if (s.top() != '(' && s.top() != '{') {
			postfix.append(1, s.top());
			postfix.append(1,' ');
			s.pop();
		} else {
			bracketError();
			break;
		}
	}
	
	return postfix;
}

double parseToDouble(const string& postfix) {
	stack<double> s;
	int size = postfix.size();
	
	for (int i = 0; i < size; ++i) {
		
		if (postfix[i] == ' ')continue;
		
		if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.') {
			
			//��������
			double temp = 0.0;
			--i;
			
			while (postfix[i+1] >= '0' && postfix[i+1] <= '9') {
				temp *= 10;
				temp += postfix[i+1] - '0';
				++i;
			}
			
			if (postfix[i+1] == '.') {
				++i;
				double base = 0.1;
				while (postfix[i+1] >= '0' && postfix[i+1] <= '9') {
					temp += base * (postfix[i+1] - '0');
					base /= 10;
					++i;
				}
			}
			
			if (postfix[i+1] != ' ' && !isSymbol(postfix[i+1])) {   //postfix��û�����ţ����ÿ���
				symbolError(i+2);
				break;
			}
			
			s.push(temp);
			continue;
			
		}
		
		if (isSymbol(postfix[i])) {	//postfix��û�����ţ����ÿ���
			
			if (s.empty()) {
				symbolError(i+1);
				break;
			}
			double temp2 = s.top();
			s.pop();
			
			if (s.empty()) {
				symbolError(i+1);
				break;
			}
			double temp1 = s.top();
			s.pop();
			
			s.push(getResult(temp1, temp2, postfix[i]));
			continue;
			
		}
		
		//�Ƿ��ַ�
		cout << "Illegal character at " << i << "." << endl;
		break;
	}   //End for
	
	return s.top();
}

double evaluateInfix(const string& infix) {
	stack<double> ns;   //number stack
	stack<char> os; //operator stack
	int size = infix.size();
	char preItem = '';	//previous item('' = head of expression, '0' = number) 
	
	for (int i = 0; i < size; ++i) {
		
		if (infix[i] == ' ')continue;

		if ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {

			//��������
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

			if (infix[i+1] != ' ' && !isSymbol(infix[i+1])) {
				symbolError(i+2);
				break;
			}

			ns.push(temp);
			continue;

		}
		
		if (priority(infix[i]) == 0) {	//�Ƿ��ַ� 
			cout << "Illegal character at " << i+1 << "." << endl; 
			break;
		}
		
		if (priority(infix[i]) > 0) {   //+ - * / ( {

			while (!os.empty() && priority(os.top()) != LBRACKET && priority(infix[i]) <= priority(os.top())) {
				operate(ns, os.top());
				os.pop();
			}
			os.push(infix[i]);

		} else {    //�������������

			while (!os.empty() && isMatch(os.top(), infix[i]) == 1) {
				operate(ns, os.top());
				os.pop();
			}
			if (os.empty() || isMatch(os.top(), infix[i]) == -1) {
				bracketError(i+1);
				break;
			}
			os.pop();    //pop��������

		}
	}
	
	while (!os.empty()) {
		operate(ns, os.top());
		os.pop();
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
	if (s.empty()) {
		cout << "Illegal operator." << endl;
		return;
	} 
	double temp2 = s.top();
	s.pop();
	
	if (s.empty()) {
		cout << "Illegal operator." << endl;
		return;
	} 
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
		return -1;  //���������ȼ�Ϊ��

	case '}':
		return -2;
		
	default:
		return 0;	//�Ƿ����� 
	}
}

bool isSymbol(char c) {
	switch (c) {
	case '+': case '-': case '*': case '/': case '(': case ')': case '{': case '}':
		return true;
	default:
		return false;
	}
}

short isMatch(char left, char right) {  //ƥ�䷵��0������ƥ�䷵��-1��left�����ŷ���1
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
