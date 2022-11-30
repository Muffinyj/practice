#include <iostream>
#include <queue>

using namespace std;

bool maze[100][100];
queue<pair<int,int>> q;
bool visit[100][100] = { 0, };
int _min[100][100];
int dx[4] = { 1, -1,0,0 };
int dy[4] = { 0,0,1, -1 };
int n, m, flag = 0;

void bfs(int x, int y) {
	if (visit[x][y] == true || flag == 1) {
		q.pop();
		return;
	}
	if (x == n - 1 && y == m - 1) {
		flag = 1;
	}
	q.push(make_pair(x, y));
	visit[x][y] = true;
	_min[x][y]++;
	while (!q.empty()) {
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visit[nx][ny] != true && maze[nx][ny] == true) {
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
					_min[nx][ny] = _min[_x][_y] + 1;
				}
			}
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	string tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			maze[i][j] = (int)(tmp[j] - '0');
		}
	}

	bfs(0, 0);
	cout << _min[n-1][m-1];

	return 0;
}