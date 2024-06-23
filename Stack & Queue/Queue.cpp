#include <iostream>


using namespace std;
#define MAX 100


struct Queue {
	int a[MAX];
	int front;
	int rear;
};
void init(Queue& q) {
	q.front = q.rear = -1;
}
bool isEmpty(Queue q) {
	return q.front < 0;
}
void enQueue(Queue& q, int x) {
	if (isEmpty(q)) {
		q.a[++q.front] = x;
		q.rear++;
	}
	else {
		q.a[++q.rear] = x;
	}
}

int deQueue(Queue& q) {
	return q.a[q.front++];
}

void output(Queue q) {
	do {
		cout << deQueue(q) <<"\t";
	} while (q.front <= q.rear);
	cout << endl;
}
int main() {
	Queue q;
	init(q);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 5);
	output(q);
	return 1;
}