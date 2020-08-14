/*

	FORTRESS 
	12ms

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class INFO {
public:
	int x, y, r;
	bool operator < (INFO &info) {
		//내림차순 정렬
		return this->r > info.r;
		//권장방식은 < 를 사용하고 desc 함수를 따로 만들어서
		//sort (a, b, desc) 호출
	}
	bool isIn(INFO &info) {
		return pow(this->x - info.x, 2) + pow(this->y - info.y, 2) < pow(this->r - info.r, 2) ;
	}
};

typedef struct treenode {
	int idx;
	vector<treenode*> child;
	vector<int> depth;
}treenode;

vector<INFO> info;
int c, n;
int MAX;

treenode* make_tree(treenode* ROOT, int idx) {
	if (idx == 0) {
		treenode *root = new treenode;
		root->idx = 0;
		make_tree(root, idx + 1);
		return root;
	}
	if (idx == n)
		return NULL;

	treenode *newnode = new treenode;
	newnode->idx = idx;
	treenode *find = ROOT;
	while (1) {
		//원 i는 원 find 내부에 있음
		if (find->child.empty()) {
			find->child.push_back(newnode);
			break;
		}
		bool flag = true;
		for (int i = 0; i < find->child.size(); i++) {
			if (info[find->child[i]->idx].isIn(info[idx])) {
				find = find->child[i];
				flag = false;
				break;
			}
		}
		if (flag) {
			find->child.push_back(newnode);
			break;
		}
	}
	make_tree(ROOT, idx + 1);
	return NULL;
}


int Fortress(treenode *root) {
	//postorder traversal
	int M1 = 0, M2 = 0;

	if (root->child.empty()) {
		return 0;
	}
	for (int i = 0; i < root->child.size(); i++) {
		root->depth.push_back(Fortress(root->child[i])+1);
		if (M1 < root->depth[i]) {
			M2 = M1;
			M1 = root->depth[i];
		}
		else if (M2 < root->depth[i]) {
			M2 = root->depth[i];
		}
	}
	MAX = max(MAX, M1 + M2);
	return M1;
}


int main() {
	cin >> c;
	while (c--) {
		MAX = 0;
		cin >> n;
		info = vector<INFO>(n);
		for (int i = 0; i < n; i++) {
			cin >> info[i].x >> info[i].y >> info[i].r;
		}
		sort(info.begin(), info.end());
		treenode *root = make_tree(NULL, 0);
		Fortress(root);
		cout << MAX << "\n";
		info.clear();
		//vector<INFO>().swap(info);
	}
	return 0;
}
