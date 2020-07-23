/*
Divide and Conquer
	Divide : {begin:min}/{min+1:end}
	Merge : compare return value and get max size
	BaseCase : the case that v has 1 elemnt or all elements of v are 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX(int a, int b) {
	if (a > b) return a;
	else return b;
}

//fence : array of fence's height, h : lessened height
int getMax(vector<int> &fence, int h) {

	//basecase_1
	if (fence.size() == 1) {
		//one boards area equals its height
		int res = h + fence[0];
		//prevent memory leak
		fence.clear();
		vector<int>().swap(fence);

		return res;
	}
	//basecase_2
	if (*max_element(fence.begin(), fence.end()) == 0) {
		int res = h * fence.size();
		fence.clear();
		vector<int>().swap(fence);
		return res;
	}

	//recursion
	
	int max;
	int min = *min_element(fence.begin(), fence.end());
	for (int i = 0;i < fence.size();i++)
		fence[i] -= min;
	h += min;
	max = h * fence.size();
	
	//divide
	auto it = find(fence.begin(), fence.end(), 0);
	vector<int> head(fence.begin(), it);
	vector<int> tail(it + 1, fence.end());
	fence.clear();
	vector<int>().swap(fence);
	
	if (!head.empty()) 
		max = MAX(max, getMax(head, h));
	if (!tail.empty()) 
		max = MAX(max, getMax(tail, h));
	
	
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
		cout << getMax(fence, 0) << "\n";
	}

	return 0;
}
