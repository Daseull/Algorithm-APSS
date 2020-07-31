#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

int a, b;
bool cacheA[2][100], cacheB[2][100];
vector<long long> seqA, seqB;
vector<vector<set<long long>>> subA, subB; //subB[i]<bool, set배열들>는 i로 시작하는 증가부분수열들

void IncSqnA(int idx) {
	if (idx == -1) return;
	if (idx == seqA.size() - 1) {
		cacheA[0][idx] = true;
		set<long long> s;
		s.insert(seqA[idx]);
		subA[idx].push_back(s);
		//return;
	}

	if (!cacheA[0][idx]) {
		cacheA[0][idx] = true;
		for (int i = idx + 1; i < seqA.size(); i++) {
			//IncSqnA(i);
			if (seqA[idx] == seqA[i]) {
				cacheA[1][i] = false;
				subA[i].clear();
				vector<set<long long>>().swap(subA[i]);
			}
			if (seqA[idx] < seqA[i]) {
				cacheA[1][i] = false;
				for (int j = 0; j < subA[i].size(); j++) {
					set<long long> s(subA[i][j]);
					s.insert(seqA[idx]);
					subA[idx].push_back(s);
				}
			}
		}
		if (subA[idx].empty()) {
			set<long long> s;
			s.insert(seqA[idx]);
			subA[idx].push_back(s);
		}
	}

	//IncSqnA(idx - 1);
}


void IncSqnB(int idx) {
	if (idx == seqB.size() - 1) {
		cacheB[0][idx] = true;
		set<long long> s;
		s.insert(seqB[idx]);
		subB[idx].push_back(s);
	}

	if (!cacheB[0][idx]) {
		cacheB[0][idx] = true;
		for (int i = idx + 1; i < seqB.size(); i++) {
			//IncSqnB(i);
			if (seqB[idx] == seqB[i]) {
				cacheB[1][i] = false;
				subB[i].clear();
				vector<set<long long>>().swap(subB[i]);
			}
			if (seqB[idx] < seqB[i]) {
				cacheB[1][i] = false;
				for (int j = 0; j < subB[i].size(); j++) {
					set<long long> s;
					s.insert(seqB[idx]);
					s.insert(subB[i][j].begin(), subB[i][j].end());
					subB[idx].push_back(s);
				}
			}
		}
		if (subB[idx].empty()) {
			set<long long> s;
			s.insert(seqB[idx]);
			subB[idx].push_back(s);
		}
	}
}

int Merge(set<long long> A, set<long long> B) {
	A.insert(B.begin(), B.end());
	return A.size();
}

int getMax() {
	int M = 0;
	for (int i = 0; i < a; i++) {
		if (!cacheA[1][i]) continue;
		for (int j = 0; j < b; j++) {
			if (!cacheB[1][i]) continue;
			for (int ia = 0; ia < subA[i].size(); ia++) {
				for (int jb = 0; jb < subB[j].size(); jb++) {
					M = max(M, Merge(subA[i][ia], subB[j][jb]));
				}
			}
		}
	}

	return M;

}

void resizeSeq() {
	seqA.resize(a);
	subA.resize(a);
	seqB.resize(b);
	subB.resize(b);
}

void clearSeq() {
	seqA.clear();
	seqB.clear();
	subA.clear();
	subB.clear();
}




int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> a >> b;
		resizeSeq();
		for (int i = 0; i < a; i++)
			cin >> seqA[i];
		for (int i = 0; i < b; i++)
			cin >> seqB[i];
		memset(cacheA[0], false, sizeof(cacheA[0]));
		memset(cacheA[1], true, sizeof(cacheA[1]));
		//IncSqnA(0);
		for (int i = a - 1; i >= 0; i--)
			IncSqnA(i);

		memset(cacheB[0], false, sizeof(cacheB[0]));
		memset(cacheB[1], true, sizeof(cacheB[1]));
		//IncSqnB(0);
		for (int i = b - 1; i >= 0; i--)
			IncSqnB(i);
		cout << getMax() << "\n";
		clearSeq();
	}
	return 0;
}

