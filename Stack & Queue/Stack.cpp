#include <iostream>
#include <string>
using namespace std;
#define MAX 100

struct Stack {
	int a[MAX];
	int top;
};

void init(Stack &s) {
	s.top = -1;
}

void push(Stack& s, int x) {
	s.a[++s.top] = x;
}

int pop(Stack& s) {
	return s.a[s.top--];
}

bool isEmpty(Stack s) {
	return s.top < 0;
}
bool isFull(Stack s) {
	return s.top == MAX;
}
void output(Stack s) {
	for (int i = 0; i <= s.top; i++) {
		cout << s.a[i] << "\t";
	}cout << endl;
}
void decimalToBinary(int x) {
	Stack s;
	init(s);
	while (x != 0) {
		push(s, x % 2);
		x /= 2;
	}
	while (isEmpty(s) == false) {
		cout << pop(s);
	}cout << endl;
}

void decimalToOctal(int x) {
	Stack s;
	init(s);
	while (x != 0) {
		push(s, x % 8);
		x /= 8;
	}
	while (isEmpty(s) == false) {
		cout << pop(s);
	}cout << endl;
}

void decimalToHexan(int x) {
	Stack s;
	init(s);
	while (x != 0) {
		push(s, x % 16);
		x /= 16;
	}
	string ABC[] = { "A","B","C","D","E","F"};
	while (isEmpty(s) == false) {
		int du = pop(s);
		if (du >= 10)
			cout << ABC[du - 10];
		else
			cout << du;
	}cout << endl;
}

void outputStack(Stack& s) {
	while (isEmpty(s) == false) {
		cout << pop(s) << "\t";
	}cout << endl;
}
int main() {
	Stack s;
	init(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	outputStack(s);
	return 0;
}