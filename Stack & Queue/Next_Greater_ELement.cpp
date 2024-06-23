#include <iostream>
#include <stack>


#define MAX 100
using namespace std;


int main() {
	
	int a[MAX] = { 5,3,2,10,6,8,1,4,12,7,4 };
	int n = 11;
	stack<int> st;
	int res[MAX] = { 0 };
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (st.empty())
			st.push(i);
		else {
			while(!st.empty() && a[st.top()] < a[i]) {
				res[st.top()] = a[i];
				st.pop();
			}
			st.push(i);
		}
	}
	while (!st.empty()) {
		res[st.top()] = -1;
		st.pop();
	}
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}cout << endl;

	return 1;
}