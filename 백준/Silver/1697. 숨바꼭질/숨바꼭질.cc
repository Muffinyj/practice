#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

queue<int> q;
int n, t;
bool visit[200001];
int _min[200001];

int bfs(int v, int target) {
	int cnt = 0;
	if (visit[v] == true) {
		return 0;
	}
	q.push(v);
	visit[v] = true;
	while (!q.empty()) {
		int tmp = q.front();
		if (visit[target]) {
			return _min[target];
		}
		q.pop();
		if (1 + tmp <= 200000 && !visit[tmp + 1]) {
			visit[tmp + 1] = true;
			q.push(tmp + 1);
			_min[tmp + 1] = _min[tmp] + 1;
		}
		if (tmp >= 1 && tmp <= 200000 && !visit[tmp - 1]) {
			visit[tmp - 1] = true;
			q.push(tmp - 1);
			_min[tmp - 1] = _min[tmp] + 1;
		}
		if (2 * tmp <= 200000 && !visit[2 * tmp]) {
			visit[tmp * 2] = true;
			q.push(tmp * 2);
			_min[tmp * 2] = _min[tmp] + 1;
		}
	}
}

int main() {
	cin >> n >> t;

	cout << bfs(n, t);

	return 0;
}