#include <iostream>
#include <queue>

using namespace std;
bool visit[1001][1001];

int bfs(int s) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp;
    int cnt(0);

    q.push(make_pair(1, 0));
    while (1) {
        pair<int, int> x = q.front();
        q.pop();

        if (x.first < 1001) {
            if (!visit[x.first][x.second]) {
                visit[x.first][x.second] = true;
                //paste
                if (x.second) {
                    tmp.push(make_pair(x.first + x.second, x.second));
                }
                //copy
                tmp.push(make_pair(x.first, x.first));
                //delete
                if (x.first > 2) {
                    tmp.push(make_pair(x.first - 1, x.second));
                }
            }
        }


        if (q.empty() && !tmp.empty()) {
            cnt++;
            q = tmp;
            tmp = queue<pair<int, int>>();
        }
        if (x.first == s) {
            break;
        }
    }

    return cnt;
}

int main() {
    int s;
    cin >> s;

    cout << bfs(s);

    return 0;
}