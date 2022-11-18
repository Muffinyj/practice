#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
queue<pair<int, int>> tmp;
int iceberg[300][300];
int check[300][300];
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int x, int y) {
	int year = 0;
	int cnt = 0;
	q.push(make_pair(x, y));

	while (1) {
		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < n && nx >= 0 && ny < m && ny >= 0) {
					if (!check[nx][ny] && iceberg[nx][ny]) {
						check[nx][ny] = -2;
						q.push(make_pair(nx, ny));
					}
				}
			}
			if ((!check[cx][cy] || check[cx][cy] == -2)) {
				for (int i = 0; i < 4; i++) {
					int _x = cx + dx[i];
					int _y = cy + dy[i];
					if (iceberg[_x][_y] == 0) {
						cnt++;
					}
				}
				if (cnt) {
					check[cx][cy] = cnt;
				}
				else {
					check[cx][cy] = -1;
				}
				cnt = 0;
			}
			if (q.empty()) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (!check[i][j] && (iceberg[i][j] != 0)) {
							return year;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j] != -1) {
					iceberg[i][j] -= check[i][j];
				}
				if (iceberg[i][j] < 0) {
					iceberg[i][j] = 0;
				}
			}
		}
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				check[i][j] = 0;
				if (iceberg[i][j] && !flag) {
					q.push(make_pair(i, j));
					flag = 1;
					year++;
				}
			}
		}
		if (q.empty()) {
			return 0;
		}
	}

	return year;
}

int main() {
	int x, y;
	cin >> n >> m;
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> iceberg[i][j];
			if (iceberg[i][j] && !flag) {
				x = i;
				y = j;
				flag = 1;
			}
		}
	}

	cout << bfs(x, y);

	return 0;
}