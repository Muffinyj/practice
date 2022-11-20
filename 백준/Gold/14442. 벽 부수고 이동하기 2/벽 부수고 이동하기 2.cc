#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int n, m;
char map[1001][1001];
bool check[11][1001][1001];
queue<tuple<int, int, int>> q;
queue<tuple<int, int, int>> tmp;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int b = 0;

int bfs(int x, int y, int br) {
	check[0][x][y] = true;
	check[1][x][y] = true;
	q.push(make_tuple(x, y, br));
	int cnt = 1;

	while (!q.empty()) {
		int cx = get<0>(q.front());
		int cy = get<1>(q.front());
		int cbreak = get<2>(q.front());
		q.pop();
		if (cx == n - 1 && cy == m - 1) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && check[cbreak][nx][ny] == false) {
				if (map[nx][ny] == '0') {
					tmp.push(make_tuple(nx, ny, cbreak));
					check[cbreak][nx][ny] = true;
				}
				else if (map[nx][ny] == '1' && cbreak > 0 && check[cbreak - 1][nx][ny] == false) {
					tmp.push(make_tuple(nx, ny, cbreak - 1));
					check[cbreak - 1][nx][ny] = true;
				}
			}
		}
		if (q.empty() && !tmp.empty()) {
			q = tmp;
			tmp = queue<tuple<int, int, int>>();
			cnt++;
		}
	}

	return 0;
}

int main() {
	cin >> n >> m >> b;
	memset(check, false, sizeof(bool) * 2 * 1001 * 1001);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int result = bfs(0, 0, b);

	if (result) {
		cout << result;
	}
	else {
		cout << "-1";
	}

	return 0;
}