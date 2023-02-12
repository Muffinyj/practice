#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#define MAX 1000000001

using namespace std;

int board[10][10];
bool visited[10][10];

int _max = INT_MIN;
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool checkNeighbor(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (visited[nx][ny]) {
                return false;
            }
        }
    }
    return true;
}

void getScore(int x, int y, int idx, int sum, int k) {
    if (idx == k) {
        if (_max < sum) {
            _max = sum;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && checkNeighbor(i,j)) {
                visited[i][j] = true;
                sum += board[i][j];

                getScore(i, j, idx + 1, sum, k);

                sum -= board[i][j];
                visited[i][j] = false;
            }
        }
    }



    return;
}

int main() {
    int k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    getScore(0, 0, 0, 0, k);

    cout << _max;

    return 0;
}