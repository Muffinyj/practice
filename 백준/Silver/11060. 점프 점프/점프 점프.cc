#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int getJumpCnt(int* jump, int n) {
    int* dp = new int[n];
    bool* visit = new bool[n];
    queue<int> q, tmp;
    int cnt(0), ptr(0);

    memset(dp, 0, sizeof(int) * n);
    memset(visit, false, sizeof(bool) * n);

    q.push(jump[0]);
    visit[0] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int i = 1; i <= x; i++) {
            int cx = ptr + i;
            if (cx < n) {
                if (!visit[cx]) {
                    visit[cx] = true;
                    tmp.push(jump[cx]);
                }
            }
            else {
                break;
            }
        }
        ptr++;
        if (q.empty() && !tmp.empty()) {
            q = tmp;
            tmp = queue<int>();
            cnt++;
        }
    }

    if (ptr < n) {
        cnt = -1;
    }

    delete[] dp;
    return cnt;
}

int main() {
    int n;
    cin >> n;

    int* jump = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> jump[i];
    }

    cout << getJumpCnt(jump, n);

    delete[] jump;
    return 0;
}