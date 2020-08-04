#include <iostream>
#include <vector>
using namespace std;
/***************************
version2: Tiling�� Ȱ���� SymTiling�� ���Ѵ�.

	1. ���Ī Ÿ�ϸ� = ��ü ����� �� - ��Ī Ÿ�ϸ��� ��
		���� �� ���ϱ� ���� ��Ī Ÿ�ϸ��� ���� ���� ���Ī Ÿ�ϸ��� ���� ���Ѵ�.

	2. SymTiling(n) n�� ��Ī���� ä��� ����� ���� ��ȯ.
		��Ī�� �� ����� ������ �� �� �κ��� ���� ����. 
		���1. n�� Ȧ���̸�, ����� �ݵ�� 1���̸� �� ���� n/2�� ��������.
		���2. n�� ¦���϶� ��Ȯ�� ������ ������ �翷�� n/2�� ��������.
		���3. n�� ¦���϶� 2���� ä��� �翷�� n/2-1�� ��������.

***************************/

const int MOD = 1000000007;
int c, n;
vector<int> tile; //tile[i]�� 2*i���� Ÿ���� ���� ����� ��
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