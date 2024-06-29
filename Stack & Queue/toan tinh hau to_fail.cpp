#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

struct Node {
	char* value;
	Node* next;
};

struct Stack {
	Node* top;
};
Node* createNode(char* x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

void init(Stack& s) {
	s.top = NULL;
}
bool isEmpty(Stack s) {
	if (s.top == NULL)
		return true;
	return false;
}

void push(Stack& s, char* x) {
	Node* p = createNode(x);
	Node* q = s.top;
	if (isEmpty(s))
		s.top = p;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}
char* get(Stack s) {
	if (isEmpty(s) == false) {
		Node* p = s.top;
		Node* prev = NULL;
		while (p->next != NULL) {
			prev = p;
			p = p->next;
		}
		if (prev == NULL)
			return p->value;
		return p->value;
	}
}
void pop(Stack& s) {
	if (isEmpty(s) == false) {
		Node* p = s.top;
		Node* prev = NULL;
		while (p->next != NULL) {
			prev = p;
			p = p->next;
		}
		if (prev == NULL) {
			
			s.top = NULL;
		}
		else {
			prev->next = NULL;
		}
		delete(p);
	}
}
bool checkDau(char* c) {
	return strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0;
}
void solve(char *c) {
	Stack s;
	init(s);
	int t = 0;
	char* p = strtok(c, " ");
	while (p != NULL) {
		if (checkDau(p)) {
			int b = atoi(get(s));
			pop(s);
			int a = atoi(get(s));
			pop(s);
			if (strcmp(p, "+") == 0)
				t = a + b;
			else if (strcmp(p, "-") == 0)
				t = a - b;
			else if (strcmp(p, "*") == 0)
				t = a * b;
			else if (strcmp(p, "/") == 0)
				t = a / b;
			char tmp[MAX];
			sprintf(tmp,"%d", t);
			push(s, tmp);
		}
		else {
			push(s, p);
		}
		p = strtok(NULL, " ");
	}
	cout << get(s) << endl;
	pop(s);
	if (isEmpty(s))
		cout << "EMPTY\n";
	else cout << "NO EMPTY\n";
}

// 10 5 + 2 * 3 / => 10

int main() {
	char c[] = { "10 5 + 2 * 3 /" };
	solve(c);
	return 1;
}
