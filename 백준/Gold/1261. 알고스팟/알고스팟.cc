#include <iostream>
#include <string>
#include <queue>

using namespace std;
bool visit[101][101];
int n, m;

int bfs(string* maze) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp1;
    queue<pair<int, int>> tmp2;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int cnt(0);

    q.push(make_pair(0, 0));
    visit[0][0] = true;
    while (1) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == n - 1 && cy == m - 1) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visit[nx][ny] && maze[nx][ny] == '0') {
                    visit[nx][ny] = true;
                    tmp1.push(make_pair(nx, ny));
                }
                else if (!visit[nx][ny] && maze[nx][ny] == '1'){
                    visit[nx][ny] = true;
                    tmp2.push(make_pair(nx, ny));
                }
            }
        }

        if (q.empty()) {
            if (!tmp1.empty()) {
                q = tmp1;
                tmp1 = queue<pair<int, int>>();
            }
            else if(tmp1.empty() && !tmp2.empty()) {
                cnt++;
                q = tmp2;
                tmp2 = queue<pair<int, int>>();
            }
            else {
                break;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> m >> n;

    string* maze = new string [n];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        maze[i] = s;
    }

    cout << bfs(maze);
    
    delete[] maze;
    return 0;
}