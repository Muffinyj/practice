#include <iostream>
#include <queue>

using namespace std;

int movingPiece(int* goalPos, int* curPos, bool* visited[], int size) {
    int xRange[6] = { -2,-2,0,0,2,2 };
    int yRange[6] = { -1,1,-2,2,-1,1 };
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp;
    q.push(make_pair(curPos[0], curPos[1]));
    visited[curPos[0]][curPos[1]] = true;
    int cnt = 0;

    while (1) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == goalPos[0] && cy == goalPos[1]) {
            return cnt;
        }

        for (int i = 0; i < 6; i++) {
            int nx = cx + xRange[i];
            int ny = cy + yRange[i];

            if (nx < size && nx >= 0 && ny < size && ny >= 0) {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    tmp.push(make_pair(nx, ny));
                }
            }
        }

        if (q.empty() && !tmp.empty()) {
            q = tmp;
            tmp = queue<pair<int, int>>();
            cnt++;
        }
        else if(q.empty() && tmp.empty()) {
            return -1;
        }
    }
}

int main() {
    int n;
    cin >> n;

    bool** board = new bool* [n];

    for (int i = 0; i < n; i++) {
        board[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = false;
        }
    }

    int curPos[2] = { 0,0 };
    int goalPos[2] = { 0,0 };

    for (int i = 0; i < 2; i++) {
        cin >> curPos[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> goalPos[i];
    }

    cout << movingPiece(goalPos, curPos, board, n);

    return 0;
}