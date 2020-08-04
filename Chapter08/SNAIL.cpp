#include <iostream>
#include <vector>
using namespace std;

/******************************

	1. Climb(지난 날짜, 오른 높이)
		비가 올 확률은 75% 이고 비가 오면 2만큼, 그렇지 않으면 1만큼 오른다.
		따라서 점화식은 Climb(days, climbed) = 0.75(days+1, climed+2) + 0.25(days+1, climbed+1)
	2. cache[days][climbed] days동안 climbed만큼 올라갔을 때의 성공 확률
		현재까지 {1,1,1,2} 인 경우와 {2,1,1,1} 인 경우, 각각의 확률이 같으므로 둘다 cache[4][5] 접근하는 메모이제이션을 활용한다.

******************************/

int c, n, m;
vector<vector<double>> cache;

double Climb(int days, int climbed) {
	//basecase
	if (days == m) {
		if (climbed >= n) return 1.0;
		return 0;
	}

	double& ret = cache[days][climbed];
	if (ret != -1) return ret;
	return ret = 0.75*Climb(days + 1, climbed + 2) + 0.25*Climb(days + 1, climbed + 1);
}

int main() {
	cin >> c;
	while (c--) {
		cin >> n >> m;
		vector<int>(7, -1);
		cache = vector< vector<double>>(m + 1, vector<double>(2 * m + 1, -1)); //cache[days][climbed]
		cout << fixed;
		cout.precision(10);
		cout << Climb(0, 0) << "\n";

	}

	return 0;
}