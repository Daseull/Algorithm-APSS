#include <iostream>
#include <set>
#include <vector>
using namespace std;

//switch-clock info
set<int> swtch[10] = { {0,1,2}, {3,7,9,11}, {4,10,14,15}, {0,4,5,6,7}, {6,7,8,10,12}, {0,2,14,15}, {3,14,15}, {4,5,7,14,15}, {1,2,3,4,5}, {3,4,5,9,13} };
//how many times switch[i] is pushed 
vector<int> times(10, 0);


//judge impossible/possible(min)
int MIN(int after, int current) {
	if (after == -1) return current;
	if (current == -1) return after;
	if (after > current) return current;
	return after;
}


vector<int> input() {
	vector<int> clock(16);
	int c;
	for (int i = 0;i < 16;i++) {
		cin >> c;
		clock[i] = c / 3 % 4;
	}
	return clock;
}

//(flag==1) clockwise, (flag==3) counterclockwise
void Switch(vector<int> &clock, int swtch_idx, int flag) {
	set<int>::iterator iter;
	for (iter = swtch[swtch_idx].begin();iter != swtch[swtch_idx].end();iter++) {
		clock[*iter] = (clock[*iter] + flag) % 4; 
	}
	if (flag == 1) times[swtch_idx]++; 
	else times[swtch_idx]--;	
}

int Sync(vector<int> &clock, int swtch_idx) {
	//impossible
	if (times[swtch_idx] > 3) return -1;

	//basecase
	bool finish = true;
	for (int i = 0;i < 16;i++) {
		if (clock[i] != 0) {
			finish = false;
			break;
		}
	}	
	if (finish) {
		int cnt = 0;
		for (int i = 0;i < 10;i++)
			cnt += times[i];
		return cnt;
	}

	//recursion
	int cnt = -1;
	for (int i = swtch_idx;i < 10;i++) {
		Switch(clock, i, 1);
		cnt = MIN(cnt, Sync(clock, i));
		Switch(clock, i, 3);
	}
	return cnt;
}


int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		vector<int> clock(16);
		clock = input();
		if (clock[8] != clock[12] || clock[14] != clock[15]) cout << "-1\n";
		else cout << Sync(clock, 0) << "\n";
	}
}