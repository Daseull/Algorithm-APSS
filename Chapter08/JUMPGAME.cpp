#include <iostream>
#include <vector>
using namespace std;

bool toEnd(vector<vector<int>> &board, vector<vector<vector<bool>>> &cache, int y, int x) {
	if (board.size() - 1 < y || board[0].size() - 1 < x)
		return false;
	if (board[y][x] == 0)
		return true;

	if (!cache[0][y][x]) {
		int n = board[y][x];
		cache[0][y][x] = true;
		cache[1][y][x] = (toEnd(board, cache, y + n, x) || toEnd(board, cache, y, x + n));
	}

	return cache[1][y][x];
}


int main() {
	int C, n;
	cin >> C;
	while (C--) {
		cin >> n;
		vector<vector<vector<bool>>> cache(2, vector<vector<bool>>(n, vector<bool>(n)));
		vector<vector <int>> board(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

		if (toEnd(board, cache, 0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}
}