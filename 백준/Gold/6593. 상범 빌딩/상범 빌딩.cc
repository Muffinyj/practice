#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char building[31][31][31] = { 0, };
bool check[31][31][31] = { 0, };
queue<tuple<int, int, int>> q;
queue<tuple<int, int, int>> q1;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int l, r, c;

int bfs(int x, int y, int z) {
	int minute = 0;
	q.push(make_tuple(x, y, z));

	while (!q.empty()) {
		int cx = get<0>(q.front());
		int cy = get<1>(q.front());
		int cz = get<2>(q.front());
		q.pop();
		check[cz][cx][cy] = true;
		if (building[cz][cx][cy] == 'E') {
			return minute;
		}

		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];
			if (!check[nz][nx][ny] && nz >= 0 && nz < l && ny >= 0 && ny < c && nx >= 0 && nx < r) {
				if (building[nz][nx][ny] == '#') {
					continue;
				}
				else {
					check[nz][nx][ny] = true;
					q1.push(make_tuple(nx, ny, nz));
				}
			}
		}

		if (q.empty() && !q1.empty()) {
			q = q1;
			q1 = queue<tuple<int, int, int>>();
			minute++;
		}
	}

	return -1;
}

int main() {
	int x, y, z;
	while (1) {
		cin >> l >> r >> c;
		if (!(l || r || c)) {
			return 0;
		}
		char tmp[31];

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> tmp;
				for (int k = 0; k < c; k++) {
					if (tmp[k] == 'S') {
						x = j;
						y = k;
						z = i;
					}
					building[i][j][k] = tmp[k];
					check[i][j][k] = false;
				}
			}
		}

		int res = bfs(x, y, z);
		if (res == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << res << " minute(s).\n";
		}
		q = queue<tuple<int, int, int>>();
		q1 = queue<tuple<int, int, int>>();
	}

	return 0;
}