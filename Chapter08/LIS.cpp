#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> sequence;

int findMax() {
	int M = 1;
	for (int i = 0; i < sequence.size(); i++) {
		M = max(M, sequence[i].second);
	}
	return M;
}

void maxIncSqn(int idx) {

	pair<int, int>& ret = sequence[idx];
	if (idx == sequence.size() - 1) {
		ret.second = 1;
		return;
	}

	if (ret.second == 0) {
		for (int i = idx + 1; i < sequence.size(); i++) {
			maxIncSqn(i);
			if (ret.first < sequence[i].first) {
				ret.second = max(ret.second, sequence[i].second);
			}
		}
		ret.second += 1;
	}
}



int main() {
	int C, n, e;
	cin >> C;
	while (C--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> e;
			sequence.push_back(make_pair(e, 0));
		}
		maxIncSqn(0);
		cout << findMax() << "\n";

		sequence.clear();
	}

}