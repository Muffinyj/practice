#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int land[100][100] = { 0, };
bool check[100][100] = { 0, };
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int, int>> q;

void bfs(int x, int y) {
	check[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !check[nx][ny]) {
				q.push(make_pair(nx, ny));
				check[nx][ny] = 1;
			}
		}
	}

	return;
}

int main() {
	cin >> n;

	int result = 0;
	int max = 0, min = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> land[i][j];
			if (max < land[i][j]) {
				max = land[i][j];
			}
			if (min > land[i][j]) {
				min = land[i][j];
			}
		}
	}

	if (min == max) {
		cout << 1;
		return 0;
	}

	for (int i = min; i < max; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (land[j][k] <= i) {
					land[j][k] = 0;
					check[j][k] = 1;
				}
				else {
					check[j][k] = 0;
				}
			}
		}
		
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!check[j][k]) {
					bfs(j, k);
					tmp++;
				}
			}
		}
		if (tmp > result) {
			result = tmp;
		}
	}

	cout << result;

	return 0;
}