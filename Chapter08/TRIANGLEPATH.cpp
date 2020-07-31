#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> triangle;

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int maxPath(int y, int x) {
	if (y >= triangle.size() || x >= triangle[y].size())
		return 0;

	if (y == triangle.size() - 1)
		return triangle[y][x].first;

	if (triangle[y][x].second == -1)
		triangle[y][x].second = triangle[y][x].first + MAX(maxPath(y + 1, x), maxPath(y + 1, x + 1));

	return triangle[y][x].second;
}


int main() {
	int C;
	cin >> C;
	while (C--) {
		int n, e;
		cin >> n;
		triangle.resize(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> e;
				triangle[i].push_back(make_pair(e, -1));
			}
		}
		cout << maxPath(0, 0) << "\n";

		triangle.clear();
	}
}