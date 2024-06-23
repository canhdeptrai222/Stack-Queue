#include<iostream>

#define MAX 100
using namespace std;

struct Stack {
	int a[MAX];
	int top;
};

void init(Stack& s) {
	s.top = -1;
}

bool isEmpty(Stack s) {
	return s.top < 0;
}

bool isFull(Stack s) {
	return s.top == MAX;
}

void push(Stack& s, int x) {
	s.a[++s.top] = x;
}

int pop(Stack& s) {
	return s.a[s.top--];
}

void output(Stack s) {
	while (!isEmpty(s)) {
		cout << pop(s) << "\t";
	}cout << endl;
}

int main() {
	Stack s;
	init(s);
	push(s, 10);
	push(s, 5);
	output(s);
	return 1;
}