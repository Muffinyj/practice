#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int cnt = 0;
bool ban[201][201];
vector<int> res;

void dfs(int idx, int m, int n, int start) {
    if (idx == 3) {
        if (ban[res[0]][res[1]]) return;
        if (ban[res[0]][res[2]]) return;
        cnt++;
        return;
    }

    for (int i = start; i <= n; i++) {
        if (ban[start][i] || i == start) continue;
        res.push_back(i);
        dfs(idx + 1, m, n, i);
        res.pop_back();
        
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        ban[a][b] = true;
        ban[b][a] = true;
    }

    dfs(0, m, n, 0);

    cout << cnt;

    return 0;
}