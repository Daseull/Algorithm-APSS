#include <iostream>
#include <queue>
#include <random>
using namespace std;

int c, n, k;

int ITES() {
	queue<int> Queue;
	int sum = 0, res = 0;
	unsigned int A = 1983;

	for(int i=0;i<n;i++){
		int signal = (int)(A % 10000 + 1);
		sum += signal;
		Queue.push(signal);
		while (sum > k) {
			sum -= Queue.front();
			Queue.pop();
		}
		if (sum == k) res++;
		A = A * 214013u + 2531011u;
	}

	return res;
}

int main() {
	cin >> c;
	while (c--) {
		cin >> k >> n;
		cout << ITES() << "\n";
	}
}