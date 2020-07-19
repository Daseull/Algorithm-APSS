#include <iostream>
#include <tuple>
#include <vector>
#include <set>
using namespace std;

int method;

//Error Case
set<int> blue = { 6,10,12,14 };
set<int> red = { 5,9,12,13 };
set<int> green = { 3,9,10,11 };
set<int> vice_purple = { 1,2,4,8,15 };

//Fill info
set<int> uni = { 7,11,13,14 };

int GetUnique(vector<vector<bool>> board, int px, int py) {
	int res = 0;
	if (board[px][py]) res += 1;
	if (board[px][py + 1]) res += 2;
	if (board[px + 1][py]) res += 4;
	if (board[px + 1][py + 1]) res += 8;
	return res;
}

vector<vector<bool>> FillBoard(vector<vector<bool>> board, int px, int py, int fill_info) {
	//fill_info = 14,13,11,7
	if (fill_info == 14) {
		board[px][py + 1] = board[px + 1][py] = board[px + 1][py + 1] = true;
	}
	else if (fill_info == 13) {
		board[px][py] = board[px + 1][py] = board[px + 1][py + 1] = true;
	}
	else if (fill_info == 11) {
		board[px][py] = board[px][py + 1] = board[px + 1][py + 1] = true;
	}
	else
		board[px][py] = board[px][py + 1] = board[px + 1][py] = true;

	return board;
}

void BoardCover(vector<vector<bool>> board, int px, int py) {
	//revise px, py
	if (py == board[0].size() - 1) {
		px++;
		py = 0;
	}
	
	int unique;
	unique = GetUnique(board, px, py);
	

	//base case
	if (px == board.size() - 2 && py == board[0].size() - 2) {	
		if (vice_purple.find(unique) != vice_purple.end()) {
			method++;	
		}
		return;
	}

	//recursion
	if (blue.find(unique) != blue.end())
		return;

	set<int>::iterator iter;
	if (py == board[0].size() - 2) {
		if (red.find(unique) != red.end())
			return;
		if (unique == 0) {
			BoardCover(FillBoard(board, px, py, 11), px, py+1);
			BoardCover(FillBoard(board, px, py, 7), px, py + 1);
		}
		else {
			for (iter = uni.begin();iter != uni.end();iter++) {
				if (*iter + unique == 15) {
					
					BoardCover(FillBoard(board, px, py, *iter), px, py + 1);
				}
			}
			if(board[px][py] && board[px][py+1]) BoardCover(board, px, py + 1);
		}
	}
	else if (px == board.size() - 2) {
		if (green.find(unique) != green.end())
			return;
		if (unique == 0) {
			BoardCover(FillBoard(board, px, py, 13), px, py + 1);
			BoardCover(FillBoard(board, px, py, 7), px, py + 1);
		}
		else {
			for (iter = uni.begin();iter != uni.end();iter++) {
				if (*iter + unique == 15) {
					
					BoardCover(FillBoard(board, px, py, *iter), px, py + 1);
				}
			}
			if (board[px][py] && board[px + 1][py]) BoardCover(board, px, py + 1);
		}
	}
	else {
		if (unique == 0) {
			BoardCover(FillBoard(board, px, py, 13), px, py + 1);
			BoardCover(FillBoard(board, px, py, 11), px, py + 1);
			BoardCover(FillBoard(board, px, py, 7), px, py + 1);
		}
		else {
			for (iter = uni.begin();iter != uni.end();iter++) {
				if (*iter + unique == 15) {
		
					BoardCover(FillBoard(board, px, py, *iter), px, py + 1);
				}
			}
			if (board[px][py]) BoardCover(board, px, py + 1);
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int h, w;
		cin >> h >> w;
		vector<vector <bool>> board(h, vector<bool>(w));

		char ch;
		for (int j = 0; j < h; j++) {
			getchar();
			for (int k = 0; k < w; k++) {
				cin >> ch;
				if (ch == '#')
					board[j][k] = true;
			}
		}
		method = 0;
		BoardCover(board, 0, 0);
		cout << method << "\n";
	}
}