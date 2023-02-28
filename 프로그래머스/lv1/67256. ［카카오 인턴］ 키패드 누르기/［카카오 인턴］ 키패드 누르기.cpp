#include <string>
#include <vector>
#include <queue>

using namespace std;

int numpad[4][3] = { {11,0,12},{7,8,9},{4,5,6},{1,2,3} };
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,-1,1,0,0 };

int bfs(int& x, int& y, int n) {
    bool visited[4][3]{ false, };
    int cnt = 0;
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp;
    q.push(make_pair(x, y));

    while (1) {
        int cx = q.front().first;
        int cy = q.front().second;
        if (numpad[cx][cy] == n) {
            x = cx;
            y = cy;
            return cnt;
        }
        q.pop();
        for (int i = 0; i < 5; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < 4 && ny < 3) {
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
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    //x y
    int lptr[2] = { 0,0 };
    int rptr[2] = { 0,2 };

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            for (int k = 0; k < 4; k++) {
                for (int j = 0; j < 3; j++) {
                    if (numbers[i] == numpad[k][j]) {
                        lptr[0] = k;
                        lptr[1] = j;
                        answer += "L";
                    }
                }
            }
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            for (int k = 0; k < 4; k++) {
                for (int j = 0; j < 3; j++) {
                    if (numbers[i] == numpad[k][j]) {
                        rptr[0] = k;
                        rptr[1] = j;
                        answer += "R";
                    }
                }
            }
        }
        else {
            int lx = lptr[0], ly = lptr[1];
            int rx = rptr[0], ry = rptr[1];
            int r = bfs(rx, ry, numbers[i]);
            int l = bfs(lx, ly, numbers[i]);

            if (r == l) {
                if (hand == "right") {
                    rptr[0] = rx;
                    rptr[1] = ry;
                    answer += "R";
                }
                else {
                    lptr[0] = lx;
                    lptr[1] = ly;
                    answer += "L";
                }
            }
            else {
                if (r > l) {
                    lptr[0] = lx;
                    lptr[1] = ly;
                    answer += "L";
                }
                else {
                    rptr[0] = rx;
                    rptr[1] = ry;
                    answer += "R";
                }
            }
        }
    }

    return answer;
}