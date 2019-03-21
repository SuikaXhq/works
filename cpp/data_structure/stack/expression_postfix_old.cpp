#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

string parsePostfix(const string&);    //Infix -> Postfix
double evaluatePostfix(const string&); //Postfix -> double
void unmatchedParenthesisError(int=0);

int main() {
	string a = "( 7 * 2 - ( 3 * { 1 / 5 + 22 * 2 } - { 6 } ) - 5 * 4 )";
	cout << parsePostfix(a);
}

string parsePostfix(const string& infix){
	int size = infix.size();
	string postfix;
	stack<char> opStack;
	for (int i = 0; i < size; ++i) {

		switch (infix[i]) {

        case ' ':
        	break;

		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			postfix.append(1, infix[i]);
			if (i != size-1 && infix[i+1] == ' ') {
				postfix.append(1,' ');
   			}
   			break;

		case '+': case '-':
			while (!opStack.empty() && (opStack.top() == '+' || opStack.top() == '-' || opStack.top() == '*' || opStack.top() == '/')) {
				postfix.append(1, opStack.top());
				if (i != size-1) {
					postfix.append(1,' ');
				}
				opStack.pop();
			}
			opStack.push(infix[i]);
			break;

		case '*': case '/':
			while (!opStack.empty() && (opStack.top() == '*' || opStack.top() == '/')) {
				postfix.append(1, opStack.top());
				if (i != size-1) {
					postfix.append(1,' ');
				}
				opStack.pop();
			}
			opStack.push(infix[i]);
			break;

		case '(': case '{':
			opStack.push(infix[i]);
			break;

		case ')':
			while (!opStack.empty() && opStack.top() != '(') {
				if (opStack.top() == '{') {
					unmatchedParenthesisError(i+1);
					return "";
				}
				postfix.append(1, opStack.top());
				postfix.append(1,' ');
				opStack.pop();
			}
			if (opStack.empty()) {
				unmatchedParenthesisError(i+1);
				return "";
			}
			opStack.pop();  //popµô×óÀ¨ºÅ
			break;

		case '}':
			if (opStack.empty()) {
				unmatchedParenthesisError(i+1);
				return "";
			}
			while (!opStack.empty() && opStack.top() != '{') {

				if (opStack.top() == '(') {
					unmatchedParenthesisError(i+1);
					return "";
				}
				postfix.append(1, opStack.top());
				postfix.append(1,' ');
				opStack.pop();
			}
			if (opStack.empty()) {
				unmatchedParenthesisError(i+1);
				return "";
			}
			opStack.pop();  //popµô×óÀ¨ºÅ
			break;
		}
	}   //end for

	while (!opStack.empty()) {
		if (opStack.top() != '(' && opStack.top() != '{') {
			postfix.append(1, opStack.top());
			postfix.append(1,' ');
			opStack.pop();
		} else {
			unmatchedParenthesisError();
			return "";
		}
	}

	return postfix;
}

void unmatchedParenthesisError(int index) {
	cout << "Illegal expression. The parenthesis doesn't have a matched one.";
	if (index != 0) {
		cout << "(At " << index << ")";
	}
}

double evaluatePostfix(const string& postfix) {
	stack<double> numberStack;
	int size = postfix.size();
	for (int i = 0; i < size; i++) {

		switch(postfix[i]) {

		case ' ':
			break;

		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			break;

  		case '+': case '-': case '*': case '/':
  			if (n)
  			break;
		}
	}
}

