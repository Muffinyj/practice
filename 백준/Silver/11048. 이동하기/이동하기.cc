#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    int** maze = new int*[n + 1];
    int** dp = new int*[n + 1];

    for (int i = 0; i <= n; i++) {
        maze[i] = new int[m + 1];
        dp[i] = new int[m + 1];
    }
    for (int i = 0; i < n; i++) {
        memset(dp[i], 0, sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            dp[i][j] = maze[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dx[3] = { 1,0,1 };
            int dy[3] = { 0,1,1 };
            int sum[3] = { dp[i][j] + maze[i + 1][j], dp[i][j] + maze[i][j + 1] ,dp[i][j] + maze[i + 1][j + 1] };
            for (int k = 0; k < 3; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < n && ny < m) {
                    if (sum[k] >= dp[nx][ny]) {
                        dp[nx][ny] = sum[k];
                    }
                }
            }
        }
    }

    cout << dp[n - 1][m - 1];

    for (int i = 0; i < n; i++) {
        delete[] maze[i];
        delete[] dp[i];
    }
    delete[] maze;
    delete[] dp;

    return 0;
}