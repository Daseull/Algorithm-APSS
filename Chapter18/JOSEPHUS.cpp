#include <iostream>
#include <list>
using namespace std;

/*******************

	선삭제 후이동.
	erase()가 삭제한 노드의 다음 노드의 주소를 반환함을 유의
	end()가 마지막 노드의 주소가 아님을 유의
	list.size() 보다 전역변수 n을 사용하는 것이 더 빠르다.

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