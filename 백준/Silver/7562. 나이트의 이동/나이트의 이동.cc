#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int board[300][300];
bool visit[300][300];
int _min[300][300];
int dx[8] = { 1, 2, 2, 1, -1, -2, -1, -2 };
int dy[8] = { 2, 1, -1, -2, 2, 1, -2, -1 };
int n, l;

int bfs(int cx, int cy, int tx, int ty) {
	visit[cx][cy] = true;
	q.push(make_pair(cx, cy));
	if (cx == tx && cy == ty) {
		return _min[tx][ty];
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
				_min[nx][ny] = _min[x][y] + 1;
			}
			if (nx == tx && ny == ty) {
				return _min[tx][ty];
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> l;

		for (int j = 0; j < l; j++) {
			for (int k = 0; k < l; k++) {
				_min[j][k] = false;
				visit[j][k] = false;
			}
		}
		q = queue < pair<int, int>>();
		int cx, cy, dx, dy;
		cin >> cx >> cy;
		cin >> dx >> dy;
		cout << bfs(cx, cy, dx, dy) << '\n';

	}

	return 0;
}