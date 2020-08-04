#include <iostream>
#include <vector>
using namespace std;

/***************************
version1 : SymTiling�� Tiling�� ����� ���� ���������, Tiling�� Ȱ�������ʰ� ���������� ���Ѵ�.(version2���� ����)

	1. ���Ī Ÿ�ϸ� = ��ü ����� �� - ��Ī Ÿ�ϸ��� ��
		���� �� ���ϱ� ���� ��Ī Ÿ�ϸ��� ���� ���� ���Ī Ÿ�ϸ��� ���� ���Ѵ�.

	2. SymTiling(n) n�� ��Ī���� ä��� ����� ���� ��ȯ.
		�¿� ��Ī�� ��� �� ���� 1�̸� �� ���� 1, �� ���� 2�̸� ���� 2 �̴�.
		���� ���縦 1(2)�� ä��� �ڵ����� �����ϴ� ���� 1(2)�� �ǹǷ� ������ n-2(n-4)���� ��Ī���� ä��� ����� ���� ���Ѵ�.
		��ȭ�� : SymTiling(n) = SymTiling(n-2) + SymTiling(n-4)

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