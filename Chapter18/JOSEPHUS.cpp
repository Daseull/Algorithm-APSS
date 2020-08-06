#include <iostream>
#include <list>
using namespace std;

/*******************

	������ ���̵�.
	erase()�� ������ ����� ���� ����� �ּҸ� ��ȯ���� ����
	end()�� ������ ����� �ּҰ� �ƴ��� ����
	list.size() ���� �������� n�� ����ϴ� ���� �� ������.

*******************/

int c, n, k;
list<int> soldier;

void Josephus() {
	list<int>::iterator kill;
	kill = soldier.begin();
	while (n > 2) {
		kill = soldier.erase(kill);
		n--;
		if (kill == soldier.end())
			kill = soldier.begin();
		for (int i = 0; i < k-1; i++) {
			kill++;
			if (kill == soldier.end())
				kill = soldier.begin();
		}
	}
	cout << soldier.front() << " " << soldier.back() << "\n" ;
	soldier.clear();
}


int main() {
	cin >> c;
	while (c--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			soldier.push_back(i);
		}

		Josephus();
	}
	return 0;
}