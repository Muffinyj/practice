#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char building[1000][1000] = { ' ', };
bool check[1000][1000] = { false, };
queue<pair<int, int>> q;
queue<pair<int, int>> q1;
queue<pair<int, int>> fire;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int w, h, x, y;

void burnt(int cnt) {
	int n = fire.size();
	for (int j = 0; j < n; j++) {
		int fx = fire.front().first;
		int fy = fire.front().second;
		fire.pop();
		for (int k = 0; k < 4; k++) {
			int nfx = fx + dx[k];
			int nfy = fy + dy[k];
			if (nfx >= 0 && nfy >= 0 && nfx < h && nfy < w) {
				if (building[nfx][nfy] == '.') {
					building[nfx][nfy] = '#';
					fire.push(make_pair(nfx, nfy));
				}
			}
		}
	}
}

int bfs(int x, int y) {
	q.push(make_pair(x, y));
	check[x][y] = 1;
	int cnt = 1;
	burnt(cnt);

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (cx == 0 || cy == 0 || cx == h - 1 || cy == w - 1) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (building[nx][ny] != '#' && !check[nx][ny]) {
					q1.push(make_pair(nx, ny));
					check[nx][ny] = 1;
				}
			}
		}

		if (q.empty() && !q1.empty()) {
			q = q1;
			q1 = queue<pair<int, int>>();
			cnt++;
			burnt(cnt);
		}
	}

	return -1;
}

bool input() {
	char s[1000];
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> building[i][j];
			if (building[i][j] == '*') {
				fire.push(make_pair (i, j));
				building[i][j] = '#';
			}
			else if (building[i][j] == '@') {
				x = i;
				y = j;
			}
		}
	}

	return 1;
}

int main() {
	queue<int> result;
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int num = 0; num < n; num++) {
		int res = 0;

		if (input()) {
			res = bfs(x, y);
			
			result.push(res);

			fire = queue<pair<int, int>>();
			q1 = queue<pair<int, int>>();
			q = queue<pair<int, int>>();
			memset(building, ' ', sizeof(building));
			memset(check, false, sizeof(check));
		}
	}

	while(!result.empty()) {
		if (result.front() == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << result.front() << "\n";
		}
		result.pop();
	}

	return 0;
}