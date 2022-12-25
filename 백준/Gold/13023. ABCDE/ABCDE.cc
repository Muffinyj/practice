#include <iostream>
#include <vector>
#define MAX 2000

using namespace std;

vector<int> friends[MAX];
bool visited[MAX] = { false, };
int hop(1);
int a, b;
bool flag(0);

void dfs(int num, int cnt) {
    if (hop == 5) {
        flag = 1;
    }
    else {
        for (int i = 0; i < friends[num].size(); i++) {
            int x = friends[num][i];
            if (!visited[x]) {
                visited[x] = true;
                hop++;
                dfs(x, hop);
                hop--;
                visited[x] = false;
            }
        }
    }
}

int main() {
    cin >> a >> b;

    for (int i = 0; i < b; i++) {
        int n, v;
        cin >> n >> v;
        friends[n].push_back(v);
        friends[v].push_back(n);
    }

    for (int i = 0; i < a; i++) {
        visited[i] = true;
        dfs(i, hop);
        visited[i] = false;
        if (flag) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}