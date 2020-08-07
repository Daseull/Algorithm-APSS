#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*********************************

	�ܾ��� ���° ���ڷν� �ش� ���ڸ� �����ߴ��� �޸������̼� �س��´�.
	AAAAA 
	AAAAA
	AAAAA
	AAACC
	AAACB �� ���Ͽ� [2][2]�� �ش��ϴ� A�� �ֺ��� ���ڷ����� �ι�°, ����°, .... ���ڷμ� �ݺ��Ǿ� ���ٵǴµ� ������ ���� ���θ� �����Ͽ� �ݺ�����ϴ� ���� ������ �Ѵ�.

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