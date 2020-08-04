#include <iostream>
#include <vector>
using namespace std;
/***************************
version2: Tiling을 활용해 SymTiling을 구한다.

	1. 비대칭 타일링 = 전체 경우의 수 - 대칭 타일링의 수
		따라서 더 구하기 쉬운 대칭 타일링의 수를 구해 비대칭 타일링의 수를 구한다.

	2. SymTiling(n) n을 대칭으로 채우는 방법의 수를 반환.
		대칭일 때 가운데를 제외한 양 옆 부분은 서로 같다. 
		가운데1. n이 홀수이면, 가운데는 반드시 1개이며 양 옆은 n/2로 나눠진다.
		가운데2. n이 짝수일때 정확히 반으로 나누면 양옆은 n/2로 나눠진다.
		가운데3. n이 짝수일때 2개로 채우면 양옆은 n/2-1로 나눠진다.

***************************/

const int MOD = 1000000007;
int c, n;
vector<int> tile; //tile[i]는 2*i개의 타일을 덮는 방법의 수
vector<int> sym;
int Tiling(int n) {
	if (tile[n] != -1) return tile[n];
	
	int& ret = tile[n];
	if (n <= 1) return ret = 1;
	if (n == 2) {
		return ret = 2;
	}
	return ret = (Tiling(n - 1) + Tiling(n - 2)) % MOD;
}

int SymTiling(int n) {
	if (n % 2 == 1) 
		return Tiling(n / 2);
	return (Tiling(n / 2) + Tiling(n / 2 - 1))%MOD;
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