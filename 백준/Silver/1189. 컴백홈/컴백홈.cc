#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>

using namespace std;

char map[5][5];
bool visited[5][5];
int r, c, k, cnt(0);
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int idx, int x, int y) {
    if (idx == k - 1&& x == 0 && y == c - 1) {
        cnt++;

        return;
    }
    else if (idx == k) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if (!visited[nx][ny] && map[nx][ny] != 'T') {
                visited[nx][ny] = true;
                dfs(idx + 1, nx, ny);
                visited[nx][ny] = false;
            }
        }
    }

    return;
}

int main() {
    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    visited[r - 1][0] = true;
    dfs(0, r - 1, 0);

    cout << cnt;

    return 0;
}