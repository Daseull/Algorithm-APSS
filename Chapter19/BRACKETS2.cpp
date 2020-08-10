#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int c;
string str;
vector<pair<char, char>> bracket = { make_pair('(', ')') , make_pair('{', '}'), make_pair('[', ']') };

bool checkBracket() {
	stack<char> Stack;
	string::iterator it;
	for (it = str.begin(); it != str.end(); it++) {
		for (int i = 0; i < 3; i++) {
			if (*it == bracket[i].first)
				Stack.push(*it);
			else if (*it == bracket[i].second) {
				if (Stack.empty())
					return false;
				if (Stack.top() == bracket[i].first)
					Stack.pop();
				else
					return false;
			}
		}
	}

	if (Stack.empty()) return true;
	return false;
}

int main() {
	cin >> c;
	while (c--) {
		cin >> str;
		if (checkBracket()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

/*
bool isMatch(char c1, char c2) {
	if (c1 == ')') return c2 == '(';
	if (c1 == '}') return c2 == '{';
	if (c1 == ']') return c2 == '[';
	return false;
}
*/