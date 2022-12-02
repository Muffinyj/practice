#include <iostream>
#include <queue>

using namespace std;

bool field[50][50] = { 0, };
bool visit[50][50] = { 0, };
queue<pair<int,int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt = 0;
int low, col, cab, x, y;

void bfs(int x, int y) {
	if (visit[x][y] == true) {
		return;
	}
	visit[x][y] = true;
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && nx < low && ny >= 0 && ny < col) {
				if (field[nx][ny] == true && visit[nx][ny] != true) {
					q.push(make_pair(nx, ny));
					bfs(nx, ny);
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> low >> col >> cab;

		for (int a = 0; a < low; a++) {
			for (int b = 0; b < col; b++) {
				visit[a][b] = false;
				field[a][b] = false;
			}
		}

		for (int j = 1; j <= cab; j++) {
			cin >> x >> y;
			field[x][y] = true;
		}
		for (int j = 0; j < low; j++) {
			for (int k = 0; k < col; k++) {
				if (field[j][k] == true && visit[j][k] != true) {
					q.push(make_pair(j, k));
					bfs(q.front().first, q.front().second);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
}