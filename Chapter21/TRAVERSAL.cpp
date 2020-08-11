#include <iostream>
#include <vector>
using namespace std;

int c, n;

typedef struct Tree {
	int e;
	struct Tree *left, *right;
}Tree;

Tree* makeTree(vector<int> pre, vector<int> in, int n) {
	if (n == 0) return NULL;
	
	Tree *newnode = new Tree;
	newnode->e = pre[0];
	
	int i, left, right;
	for (i = 0; i < n; i++) {
		if (pre[0] == in[i]) {
			left = i;
			right = n - i - 1;
			break;
		}
	}
	newnode->left = makeTree(vector<int>(pre.begin() + 1, pre.begin() + 1 + left), vector<int>(in.begin(), in.begin() + i), left);
	newnode->right = makeTree(vector<int>(pre.end()-right, pre.end()), vector<int> (in.end() - right, in.end()), right);

	cout << newnode->e << " ";

	return newnode;
}

/*
void pstTrv(Tree *root){
	if (root->left != NULL) pstTrv(root->left);
	if (root->right != NULL) pstTrv(root->right);
	cout << root->e << " ";
}
*/

int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		vector<int> preorder(n), inorder(n);
		for (int i = 0; i < n; i++)
			cin >> preorder[i];
		for (int i = 0; i < n; i++)
			cin >> inorder[i];
		
		Tree *root = makeTree(preorder, inorder, n);
		//pstTrv(root);
		cout << "\n";
	}
}