#include <iostream>
#include <list>
using namespace std;

/**********************************

	삭제할 노드를 임시로 저장해놓고 이동 후 삭제한다. 
	Error: 5,5 등을 입력했을 때 stackoverflow 발생, 이 경우 새로 찾은 start가 삭제할 노드 obj와 같아진다. 선 삭제, 후 이동해야함. 

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