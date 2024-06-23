#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#define MAX 100
using namespace std;
bool checkDau(char* c) {
	return strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0;
}
int calculate(int a, int b, char* dau) {
	if (strcmp(dau, "+") == 0)
		return a + b;
	else if (strcmp(dau, "-") == 0)
		return a - b;
	else if (strcmp(dau, "*") == 0)
		return a * b;
	else if (strcmp(dau, "/") == 0)
		return a / b;
}
int calHauTo(char* s) {
	stack <int> so;
	char* token = strtok(s, " ");
	int t = 0;
	while (token != NULL) {
		if (checkDau(token)) {
			int b = so.top();
			so.pop();
			int a = so.top();
			so.pop();
			t = calculate(a, b, token);
			so.push(t);
		}
		else {
			so.push(atoi(token));
		}
		token = strtok(NULL, " ");
	}
	return so.top();
}

int main() {
	char s[] = "10 3 * 5 + 10 - 15 *"; //=> res = 150
	cout << calHauTo(s);

	return 1;
}