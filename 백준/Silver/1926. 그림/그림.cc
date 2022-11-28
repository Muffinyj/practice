#include <iostream>
#include <queue>

using namespace std;

bool visit[500][500] = { 0, };
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int l, w;
int cnt = 0, area = 0;

void bfs() {
	if (visit[q1.front().first][q1.front().second]) {
		return;
	}
	int tmp = 0;
	visit[q1.front().first][q1.front().second];
	while (!q1.empty()) {
		int x, y;
		x = q1.front().first;
		y = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!visit[nx][ny] && nx >= 0 && nx < l && ny >= 0 && ny < w) {
				visit[nx][ny] = true;
				q2.push(make_pair(nx, ny));
				tmp++;
			}
		}
		if (q1.empty() && !q2.empty()) {
			q1 = q2;
			q2 = queue<pair<int, int>>();
		}
	}
	if (area < tmp) {
		area = tmp;
	}
	cnt++;
	return;
}

int main() {
	cin >> l >> w;
	int flag = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			int tmp = 0;
			cin >> tmp;
			if (!tmp) {
				visit[i][j] = true;
			}
		}
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			if (!visit[i][j]) {
				q1.push(make_pair(i, j));
				flag = 1;
				bfs();
			}
		}
	}

	if (flag && area == 0) {
		area = 1;
		cout << cnt << '\n' << area;
	}
	else {
		cout << cnt << '\n' << area;
	}
	return 0;
}