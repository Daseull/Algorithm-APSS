/*
Get width comparing adjacent element

This source solves the examples but has Time Limit Exceed error
There's ver2 that overcome TLE
*/

#include <iostream>
#include <vector>
using namespace std;
#define MAX(a, b) (((a)>(b))? (a):(b)) 

int getLength(vector<int> fence, int idx) {
	int len = 0;

	for (int i = idx; i >= 0;i--) {
		if (fence[i] >= fence[idx])
			len++;
		else
			break;
	}
	for (int i = idx;i < fence.size();i++) {
		if (fence[i] >= fence[idx])
			len++;
		else 
			break;
	}
	return len-1;	
}


int GetMax(vector<int> fence) {
	int max = 0;

	for (int i = 0;i < fence.size();i++) {
		int m = fence[i] * getLength(fence, i);
		max = MAX(max, m);
	}
	return max;
}

int main() {
	int C, n, e;
	cin >> C;
	while (C--) {
		cin >> n;
		vector<int> fence(n);
		for (int i = 0;i < n;i++) {
			cin >> e;
			fence[i] = e;
		}
		cout << GetMax(fence) << "\n";
	}

	return 0;
}

