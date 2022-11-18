#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int aquarium[20][20];
bool visit[20][20] = { 0, };
int weight = 2, eatNum = 0, cnt = 1;
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
vector<tuple<int, int, int>> eat;
int n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int compare(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    if (get<2>(a) < get<2>(b)) {
        return 1;
    }
    else if (get<2>(a) == get<2>(b)) {
        if (get<0>(a) < get<0>(b)) {
            return 1;
        }
        else if (get<0>(a) == get<0>(b)) {
            if (get<1>(a) < get<1>(b)) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int bfs(int cx, int cy) {
    int tmp = 0;

    q1.push(make_pair(cx, cy));
    visit[cx][cy] = true;
    while(1) {
        while (!q1.empty()) {
            int x = q1.front().first;
            int y = q1.front().second;
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (weight > aquarium[nx][ny] && aquarium[nx][ny] && !visit[nx][ny]) {
                        eat.push_back(make_tuple(nx, ny, cnt));
                        visit[nx][ny] = true;
                    }
                    else if ((weight == aquarium[nx][ny] || !aquarium[nx][ny]) && !visit[nx][ny]) {
                        if (x != nx || y != ny) {
                            q2.push(make_pair(nx, ny));
                            visit[nx][ny] = true;
                        }
                    }
                    else {
                        continue;
                    }
                }
            }
            if (q1.empty() && !q2.empty()) {
                cnt++;
                q1 = q2;
                q2 = queue<pair<int, int>>();
            }
        }
        //먹을 수 있는 생선들이 eat queue에 들어가있다.
        if (eat.empty()) {
            return tmp;
        }
        else {
            sort(eat.begin(), eat.end(), compare);

            int tx = get<0>(eat.front());
            int ty = get<1>(eat.front());

            eatNum++;
            if (eatNum == weight) {
                weight++;
                eatNum = 0;
            }
            aquarium[cx][cy] = 0;
            aquarium[tx][ty] = 9;
            cx = tx;
            cy = ty;
            q1 = queue<pair<int, int>>();
            q2 = queue<pair<int, int>>();
            q1.push(make_pair(tx, ty));
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    visit[j][k] = false;
                }
            }
            tmp += get<2>(eat.front());
            cnt = 1;
            visit[cx][cy] = true;

            eat = vector<tuple<int, int, int>>();
        }
    }
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aquarium[i][j];
            if (aquarium[i][j] == 9) {
                x = i;
                y = j;
            }
        }
    }

    cout << bfs(x, y);
    return 0;
}