#include <iostream>
#include <list>
using namespace std;

/**********************************

	������ ��带 �ӽ÷� �����س��� �̵� �� �����Ѵ�. 
	Error: 5,5 ���� �Է����� �� stackoverflow �߻�, �� ��� ���� ã�� start�� ������ ��� obj�� ��������. �� ����, �� �̵��ؾ���. 

**********************************/

int c, n, k;
list<int> soldier;

void Josephus() {
	list<int>::iterator start, obj;
	start = soldier.begin();
	while (soldier.size() != 2) {
		obj = start;
		for (int i = 0; i < k; i++) {
			start++;
			if (start == soldier.end())
				start = soldier.begin();
		}
		soldier.erase(obj);
	}
}


int main() {
	cin >> c;
	while (c--) {
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			soldier.push_back(i + 1);
		}

		Josephus();
		cout << soldier.front() << " " << soldier.back() << "\n";
		soldier.clear();
	}
	return 0;
}