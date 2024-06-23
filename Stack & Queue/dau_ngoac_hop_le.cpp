#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkNgoac(string s) {
	stack<int>ngoac;
	stack<pair<int, int>> res;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			ngoac.push(i);
		}
		else {
			if (ngoac.empty()) {
				return false;
			}
			char ngoacMo = ngoac.top();
			res.push({ ngoacMo, i });
			ngoac.pop();
		}
	}
	while (!res.empty()) {
		auto x = res.top();
		res.pop();
		cout << x.first << "-" << x.second << endl;
	}
	return ngoac.empty();
}

int main() {
	string s;
	getline(cin, s);
	if (checkNgoac(s))
		cout << "VALID\n";
	else
		cout << "INVALID\n";
	return 1;
}