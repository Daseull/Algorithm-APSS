#include <iostream>
#include <string>
using namespace std;

int revise(int i) {
	if (i == 0) return 1;
	else if (i == 4) return 3;
	else return i;
}

bool find_Word(string *str, string word, int x, int y) {
	if (word.size() == 0) return true;
	for (int i = revise(x) - 1; i < revise(x)+2;i++) {
		for (int j = revise(y) - 1; j < revise(y) + 2;j++) {
			if (i == x && j == y) continue;
			if (str[i][j] == word.front() && find_Word(str, word.substr(1), i, j))
				return true;
		}
	}
	return false;
}
void find_Front(string *str, string word) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0; j < 5; j++) {
			if (str[i][j] == word.front() && find_Word(str, word.substr(1), i, j)) {
				cout << word << " YES\n";
				return;
			}
		}
	}
	cout << word << " NO\n";
	
}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		string str[5];
		for (int j = 0;j < 5;j++) 
			cin >> str[j];
		int m;
		cin >> m;
		string *word = new string[m];
		for (int j = 0;j < m;j++) {
			cin >> word[j];
			find_Front(str, word[j]);
		}
	}
	return 0;
}
