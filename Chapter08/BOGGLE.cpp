#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*********************************

	단어의 몇번째 글자로써 해당 글자를 접근했는지 메모이제이션 해놓는다.
	AAAAA 
	AAAAA
	AAAAA
	AAACC
	AAACB 에 대하여 [2][2]에 해당하는 A는 주변의 글자로인해 두번째, 세번째, .... 글자로서 반복되어 접근되는데 각각의 접근 여부를 저장하여 반복계산하는 일이 없도록 한다.

*********************************/

int c, n;
string board[5];
string word;
bool cache[10][5][5];

int revise(int pos) {
	if (pos == -1) return 0;
	if (pos == 5) return 4;
	return pos;
}

bool find_Word(int numth, string segment, int y, int x) {
	if (segment.size() == 0) return true;
	if (cache[numth][y][x] == true) return false;
	if (word.size() == segment.size()) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (board[i][j] == segment.front() && find_Word(1, segment.substr(1), i, j)) {
					return true;
				}
			}
		}
		return false;
	}

	for (int i = revise(y - 1); i <= revise(y + 1); i++) {
		for (int j = revise(x - 1); j <= revise(x + 1); j++) {
			if (i == y && j == x) 
				continue;
			if (board[i][j] == segment.front() && find_Word(numth+1, segment.substr(1), i, j))
				return true;
		}
	}
	cache[numth][y][x] = true;
	return false;
}

int main() {
	cin >> c;
	while(c--){
		for (int j = 0; j < 5; j++)
			cin >> board[j];
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> word;
			memset(cache, false, sizeof(cache));
			if (find_Word(0, word, 0,0)) cout << word << " YES\n";
			else cout << word << " NO\n";
		}
	}
	return 0;
}