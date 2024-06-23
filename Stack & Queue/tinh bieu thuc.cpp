#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

void cal(stack<int>& so, char op) {
	int y = so.top();
	so.pop();
	int x = so.top();
	so.pop();
	switch (op) {
	case '+':
		so.push(x + y);
		break;
	case '-':
		so.push(x - y);
		break;
	case '*':
		so.push(x * y);
		break;
	case '/':
		so.push(x / y);
		break;
	}
}
void solveBieuthuc(string s) {
	stack<int>so;
	stack<char>dau;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			so.push(s[i] - '0');
		else {
			if (!dau.empty()) {
				char op = dau.top();
				dau.pop();

				cal(so, op);
			}
			dau.push(s[i]);
		}
	}
	if (!dau.empty()) {
		char op = dau.top();
		dau.pop();
		cal(so, op);
	}
	int result = so.top();
	so.pop();
	cout << "Ket qua cua bieu thuc " << s <<" = " << result  << endl;
	
}
// example "1 + 2 + 3 - 4 - 5 + 9" = 6
int main() {
	string s = "1+2";
	solveBieuthuc(s);

	return 1;
}