#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int slink[21][21];
int m = INT_MAX;
bool visited[22];

void dfs(int idx, int n, int x) {
    if (idx == n / 2) {
        int s(0), l(0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (visited[i] && visited[j]) s += slink[i][j] + slink[j][i];
                if (!visited[i] && !visited[j]) l += slink[i][j] + slink[j][i];
            }
        }

        if (m > abs(s/2 - l/2)) {
            m = abs(s/2 - l/2);
        }

        return;
    }

    //true인 곳은 start, false 인 곳은 link라고 생각
    for (int i = x; i <= n; i++) {
        visited[i] = true;
        dfs(idx + 1, n, i + 1);
        visited[i] = false;
    }

    return;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> slink[i][j];
        }
    }

    dfs(0, n, 1);

    cout << m;

    return 0;
}