#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
queue<int> tmp;

int dp(int n) {
	q.push(n);
	int cnt = 0;

	while (!q.empty()) {
		int x = q.front();
		if (x == 1) {
			return cnt;
		}
		q.pop();
		if (x % 3 == 0) {
			tmp.push(x / 3);
		}
		if (x % 2 == 0) {
			tmp.push(x / 2);
		}
		if (x > 1) {
			tmp.push(x - 1);
		}

		if (q.empty() && !tmp.empty()) {
			q = tmp;
			tmp = queue<int>();
			cnt++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	 
 	cout << dp(n);

	return 0;
}