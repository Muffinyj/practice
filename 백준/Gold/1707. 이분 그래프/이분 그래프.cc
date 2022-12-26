#include <iostream>
#include <queue>
#include <cstring>
#define MAX 20001

using namespace std;

vector<int> bigraph[MAX];
int visited[MAX];
bool flag = true;

bool checkBigraph(int num) {
    queue<int> q;
    queue<int> tmp;

    q.push(num);
    int x = num;
    if (visited[num] == -1) {
        visited[num] = !flag;
    }

    while (1) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < bigraph[x].size(); i++) {
            int nx = bigraph[x][i];

            if (visited[x] == visited[nx]) {
                return false;
            }
            else if (visited[nx] == -1) {
                visited[nx] = flag;
                tmp.push(nx);
            }
        }

        if (q.empty() && !tmp.empty()) {
            flag = !flag;
            q = tmp;
            tmp = queue<int>();
            x = q.front();
        }
        else if (q.empty() && tmp.empty()) {
            break;
        }
    }
    return true;
}

int main() {
    int k;
    bool mainFlag = true;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int num, edge;
        mainFlag = true;
        flag = true;
        cin >> num >> edge;
        //visited 초기화
        memset(visited, -1, sizeof(int) * MAX);
        for (int j = 0; j < edge; j++) {
            int n, v;
            cin >> n >> v;
            bigraph[n].push_back(v);
            bigraph[v].push_back(n);
        }

        //출력
        for (int i = 1; i <= num; i++) {
            if (!checkBigraph(i)) {
                mainFlag = false;
                break;
            }
        }
        if (mainFlag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        //벡터 초기화
        for (int i = 1; i <= num; i++) {
            bigraph[i].clear();
        }
    }

    return 0;
}