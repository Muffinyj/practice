#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int n, m;
char map[1001][1001];
bool check[2][1001][1001];
queue<tuple<int, int, bool>> q;
queue<tuple<int, int, bool>> tmp;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int x, int y) {
	check[0][x][y] = true;
	check[1][x][y] = true;
	q.push(make_tuple(x, y, false));
	int cnt = 1;

	while (!q.empty()) {
		int cx = get<0>(q.front());
		int cy = get<1>(q.front());
		bool cbreak = get<2>(q.front());
		q.pop();
		if (cx == n - 1 && cy == m - 1) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!cbreak) {
					if (check[0][nx][ny] == false && map[nx][ny] == '0') {
						tmp.push(make_tuple(nx, ny, cbreak));
						check[0][nx][ny] = true;
					}
					else if (check[1][nx][ny] == false && map[nx][ny] == '1') {
						tmp.push(make_tuple(nx, ny, !cbreak));
						check[1][nx][ny] = true;
					}
				}
				else {
					if (check[1][nx][ny] == false && map[nx][ny] == '0') {
						tmp.push(make_tuple(nx, ny, cbreak));
						check[1][nx][ny] = true;
					}
				}
			}
		}
		if (q.empty() && !tmp.empty()) {
			q = tmp;
			tmp = queue<tuple<int, int, bool>>();
			cnt++;
		}
	}

	return 0;
}

int main() {
	cin >> n >> m;
	memset(check, false, sizeof(bool) * 2 * 1001 * 1001);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int result = bfs(0, 0);

	if (result) {
		cout << result;
	}
	else {
		cout << "-1";
	}

	return 0;
}