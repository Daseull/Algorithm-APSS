#include <iostream>
#include <vector>
using namespace std;

/******************************

	1. Climb(���� ��¥, ���� ����)
		�� �� Ȯ���� 75% �̰� �� ���� 2��ŭ, �׷��� ������ 1��ŭ ������.
		���� ��ȭ���� Climb(days, climbed) = 0.75(days+1, climed+2) + 0.25(days+1, climbed+1)
	2. cache[days][climbed] days���� climbed��ŭ �ö��� ���� ���� Ȯ��
		������� {1,1,1,2} �� ���� {2,1,1,1} �� ���, ������ Ȯ���� �����Ƿ� �Ѵ� cache[4][5] �����ϴ� �޸������̼��� Ȱ���Ѵ�.

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