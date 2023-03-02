#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int cnt = 0;
int board[5][5];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> res;

void dfs(int idx,int x, int y,int sum) {
    if (idx == 6) {
        bool check = false;
        if (res.size() != 0) {
            for (int i = 0; i < res.size(); i++) {
                if (res[i] == sum) {
                    check = true;
                }
            }
        }

        if (!check) {
            res.push_back(sum);
            cnt++;
        }
        
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
            int a = board[x][y] * pow(10, 5 - idx);
            int s = sum + a;
            dfs(idx + 1, nx, ny, s);
            s -= a;
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(0, i, j, 0);
        }
    }

    cout << cnt;

    return 0;
}