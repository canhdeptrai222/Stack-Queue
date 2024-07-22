#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#define MAX 100
using namespace std;
template <typename T>
struct Stack {
	T a[MAX];
	int top;
};
template <typename T>
void init(Stack<T>& s) {
	s.top = -1;
}
template <typename T>
bool isEmpty(Stack<T> s) {
	return s.top < 0;
}
template <typename T>
bool isFull(Stack<T> s) {
	return s.top == MAX;
}
template <typename T>
void push(Stack<T>& s, T x) {
	s.a[++s.top] = x;
}
template <typename T>
T pop(Stack<T>& s) {
	return s.a[s.top--];
}
template <typename T>
T get(Stack<T> s) {
	return s.a[s.top];
}

struct Node
{
	char* value;
	Node *next;
};
struct Queue {
	Node* head;
};

void init(Queue& q)
{
	q.head = NULL;
}

Node *createNode(char* x)
{
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}
void enQueue(Queue& q,char* x)
{
	Node *p = createNode(x);
	if (q.head == NULL)
	{
		q.head = p;
	}
	else
	{
		Node *last = q.head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = p;
	}
}
char* deQueue(Queue& q)
{
	if (q.head != NULL)
	{
		char* res = q.head->value;
		Node *p = q.head;
		q.head = p->next;
		p->next = NULL;
		delete (p);
		return res;
	}
}
bool isEmpty(Queue q) {
	return q.head == NULL;
}
int getPriority(char* op) {
	if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0)
		return 2;
	if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
		return 1;
	return 0;
}
void solve(char* a) {
	Stack<char*> s; init(s);
	Queue q; init(q);
	char* token = strtok(a, " ");
	while (token != NULL) {
		if (isdigit(*token)) {
			enQueue(q, token);
		}
		else if (*token == '(')
			push(s, token);
		else if (*token ==')') {
			char* op = pop(s);
			while (*op != '(') {
				enQueue(q, op);
				op = pop(s);
			}
		}
		else {
			while (!isEmpty(s) && getPriority(token) <= getPriority(get(s))) {
				char* op = pop(s);
				enQueue(q, op);
			}
			push(s, token);
		}
		token = strtok(NULL, " ");
	}
	while (!isEmpty(s)) {
		enQueue(q, pop(s));
	}
	while (!isEmpty(q))
		cout << deQueue(q) << " ";
}
int main() {
	char s[] = { "2 + 4 - ( 5 - 3 ) / 2 + 3 - 1 * 5" };
	solve(s);

	return 1;
}