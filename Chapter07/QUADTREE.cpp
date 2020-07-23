#include <iostream>
using namespace std;

//solve problem through making tree 
//Pre-order Traversal(root-3rd-4th-1st-2nd)


class Treenode {
private:
	char e;
	Treenode* child[4];
public:
	char GetElem() { return e; }
	Treenode* GetChild(int i) { return child[i]; }
	void SetElem(char e) { this->e = e; }
	void SetChild(Treenode *child, int i) { this->child[i] = child; }
};

//return root's address(recursive)
Treenode* input() {
	Treenode *tree = new Treenode;

	char ch;
	cin >> ch;
	
	//x : root(recursion)
	//b, w : leaf(basecase)
	if (ch == 'x') {	
		tree->SetElem(ch);
		for (int i = 0;i < 4;i++) {
			tree->SetChild(input(), i);
		}
	}

	return tree;
}

void reverse(Treenode* tree){
	
	//Pre-order Traversal(root-3rd-4th-1st-2nd)
	cout << tree->GetElem();
	if (tree->GetElem() == 'x') {
		reverse(tree->GetChild(2));
		reverse(tree->GetChild(3));
		reverse(tree->GetChild(0));
		reverse(tree->GetChild(1));
	}
	delete(tree);
}


int main() {
	int c;
	Treenode *tree;
	cin >> c;
	while (c--) {
		tree = input();
		reverse(tree);
		cout << "\n";
	}
	return 0;
}