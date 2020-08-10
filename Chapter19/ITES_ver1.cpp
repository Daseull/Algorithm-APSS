#include <iostream>
#include <queue>
using namespace std;

int c, n, k;
vector<int> Signal;

int ITES() {
	makeSignal();
	queue<int> Queue;
	int sum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		sum += Signal[i];
		Queue.push(Signal[i]);
		while (sum > k) {
			sum -= Queue.front();
			Queue.pop();
		}
		if (sum == k) res++;
	}

	return res;
}

void makeSignal() {
	Signal.resize(n);
	unsigned int A = 1983;
	for (int i = 0; i < n; i++) {
		Signal[i] = (int)(A % 10000 + 1);
		A = (A * 214013 % 4294967296 + 2531011) % 4294967296;
	}
}

int main() {
	cin >> c;
	while (c--) {
		cin >> k >> n;
		cout << ITES() << "\n";
	}
	return 0;
}