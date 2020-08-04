#include <iostream>
#include <vector>
using namespace std;

/*******************************

	1. n을 1또는 2로 채운다고 생각한다.(세로 부분 신경X)
	2. Tiling(n)은 n을 1또는 2로 채우는 방법의 수
		현재를 1로 채우면 나머지 공간을 채우는 방법은 Tiling(n-1)
		현재를 2로 채우면 나머지 공간을 채우는 방법은 Tiling(n-2)
		따라서 점화식 Tiling(n) = Tiling(n-1) + Tiling(n-2)
	3. 메모이제이션을 활용해 중복 계산을 줄인다. 

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