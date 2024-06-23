#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Node {
	int value;
	Node* next;
};

struct Stack {
	Node* top;
};

Node* createNode(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}
Node* createNode(char x) {
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
void push(Stack& s, int x) {
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

void pushChar(Stack& s, char x) {
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
int popValue(Stack& s) {
	if (isEmpty(s) == false) {
		int giatri;
		Node* p = s.top;
		Node* prev = NULL;
		while (p->next != NULL) {
			prev = p;
			p = p->next;
		}
		if (prev == NULL) {
			giatri = p->value;
			s.top = NULL;
		}
		else {
			prev->next = NULL;
			giatri = p->value;
			delete(p);
		}
		return giatri;
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
			delete(p);
		}
	}
}
void outputStack(Stack s) {
	Node* p = s.top;
	while (isEmpty(s) == false) {
		cout << popValue(s) << "\t";
	}cout << endl;
}
void checkDauNgoacHopLe(string ss) {
	Stack s;
	init(s);
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] == '(')
			pushChar(s, '(');
		else {
			if (isEmpty(s)) {
				cout << "INVALID\n";
				return;
			}
			else {
				pop(s);
			}
		}
	}
	if (isEmpty(s))
		cout << "VALID\n";
	else
		cout << "INVALID\n";
}
bool isTwoCharsMatching(char a, char b) {
	if (
		(a == '[' && b == ']') ||
		(a == '<' && b == '>') ||
		(a == '{' && b == '}') ||
		(a == '(' && b == ')')
		) {
		return true;
	}
	return false;
}
bool isNgoac(char s) {
	char Ngoac[] = { '(','[','{','<',')',']','}','>' };
	for (int i = 0; i < sizeof(Ngoac); i++) {
		if (s == Ngoac[i])
			return true;
	}
	return false;
}
void checkKituDongNgoac(string ss) {
	Stack s;
	init(s);
	char Ngoac[] = { '(','[','{','<',')',']','}','>'};
	for (int i = 0; i < ss.size(); i++) {
		bool checkPush = false;
		for (int j = 0; j < sizeof(Ngoac) / 2; j++) {
			if (ss[i] == Ngoac[j]) {
				pushChar(s, Ngoac[j]);
				checkPush = true;
				break;
			}
		}
		if (isNgoac(ss[i])) {
			if (checkPush == false) {
				if (isEmpty(s)) {
					cout << "INVALID\n";
					return;
				}
				else {
					Node* p = s.top;
					while (p->next != NULL) {
						p = p->next;
					}
					if (isTwoCharsMatching(p->value, ss[i]))
						pop(s);
					else {
						cout << "INVALID\n";
						return;
					}
				}
			}
		}
	}
	if (isEmpty(s))
		cout << "VALID\n";
	else
		cout << "INVALID\n";
}

bool checkSNT(int x) {
	if (x < 2)
		return false;
	else {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0)
				return false;
		}
	}
	return true;
}
Stack StackSNT(int n) {
	Stack s;
	init(s);
	for (int i = 0; i < n; i++) {
		cout << "Nhap so thu " << i + 1 << " : ";
		int x; cin >> x;
		push(s,x);
	}
	return s;
}
void printSNT(Stack s){
	while (isEmpty(s) == false) {
		int value = popValue(s);
		if (checkSNT(value))
			cout << value << "\t";
	}cout << endl;
}

long long Stack_Giaithua(int n) {
	int res = 1;
	if (n == 0 || n == 1)
		return res;
	else {
		Stack s;
		init(s);
		while (n != 1) {
			push(s, n--);
		}
		while (isEmpty(s) == false) {
			res *= popValue(s);
		}
	}
	return res;
}

int main() {
	srand((int)time(NULL));
	char c[] = "4";
	cout << atoi(c) << endl;
	cout << char(atoi(c)) << endl;

	return 1;
}