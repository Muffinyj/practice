#include <iostream>
#include <cstring>

using namespace std;

int cnt = 0;
int p[4] = { 1,5,10,50 };
bool* check;

void setting(int n) {
    int size = n * 50 + 1;
    check = new bool[size];
    memset(check, false, sizeof(bool) * size);
}

void dfs(int start, int depth, int s, int n) {
    if (depth == n) {
        if (!check[s]) {
            check[s] = true;
            cnt++;
        }
        return;
    }
    for (int i = start; i < 4; i++) {
        int sum = s + p[i];
        dfs(i, depth + 1, sum, n);
    }
}

int main() {
    int n;
    cin >> n;

    setting(n);

    dfs(0, 0, 0, n);

    cout << cnt;

    return 0;
}