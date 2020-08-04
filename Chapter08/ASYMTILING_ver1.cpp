#include <iostream>
#include <vector>
using namespace std;

/***************************
version1 : SymTiling도 Tiling과 비슷한 식을 사용하지만, Tiling을 활용하지않고 독자적으로 구한다.(version2에서 보완)

	1. 비대칭 타일링 = 전체 경우의 수 - 대칭 타일링의 수
		따라서 더 구하기 쉬운 대칭 타일링의 수를 구해 비대칭 타일링의 수를 구한다.

	2. SymTiling(n) n을 대칭으로 채우는 방법의 수를 반환.
		좌우 대칭인 경우 맨 앞이 1이면 맨 끝도 1, 맨 앞이 2이면 끝도 2 이다.
		따라서 현재를 1(2)로 채우면 자동으로 대응하는 끝도 1(2)이 되므로 나머지 n-2(n-4)개를 대칭으로 채우는 방법의 수를 구한다.
		점화식 : SymTiling(n) = SymTiling(n-2) + SymTiling(n-4)

***************************/


const int MOD = 1000000007;
int c, n;
vector<int> tile; 
vector<int> sym;
int Tiling(int n) {
	if (tile[n] != -1) return tile[n];
	if (n <= 2) {
		return tile[n] = n;
	}
	return tile[n] = (Tiling(n - 1) + Tiling(n - 2)) % MOD;
}

int SymTiling(int n) {
	if (n < 0) return 0;
	int &ret = sym[n];
	if (ret != -1) return ret;
	if (n == 0) return ret = 1;
	if (n <= 2) return ret = n;
	return ret = (SymTiling(n - 2) + SymTiling(n - 4)) % MOD;
}

int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		tile = vector<int>(n + 1, -1);
		sym = vector<int>(n + 1, -1);
		cout << (Tiling(n) - SymTiling(n) + MOD) % MOD << "\n";
	}

}