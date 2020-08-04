#include <iostream>
#include <vector>
using namespace std;

/*******************************

	1. n�� 1�Ǵ� 2�� ä��ٰ� �����Ѵ�.(���� �κ� �Ű�X)
	2. Tiling(n)�� n�� 1�Ǵ� 2�� ä��� ����� ��
		���縦 1�� ä��� ������ ������ ä��� ����� Tiling(n-1)
		���縦 2�� ä��� ������ ������ ä��� ����� Tiling(n-2)
		���� ��ȭ�� Tiling(n) = Tiling(n-1) + Tiling(n-2)
	3. �޸������̼��� Ȱ���� �ߺ� ����� ���δ�. 

*******************************/

const int MOD = 1000000007;
int c, n;
vector<int> tile;
int Tiling(int n) {
	if (tile[n] != -1) return tile[n];
	if (n <= 1) {
		return tile[n] = n + 1;

	}
	return tile[n] = (Tiling(n - 1) + Tiling(n - 2)) % MOD;
}

int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		tile = vector<int>(n, -1);
		cout << Tiling(n - 1) << "\n";
	}

}