#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstring>
#define MAX 1000001

using namespace std;

bool check[MAX];

int bfs(int a, int k) {
    queue<int> q;
    queue<int> tmp;
    int cnt = 0;
    q.push(a);

    while (q.front() != k) {
        int x = q.front();
        q.pop();

        if (x + 1 < MAX) {
            if (!check[x + 1]) {
                check[x + 1] = true;
                tmp.push(x + 1);
            }
        }
        if (2 * x < MAX) {
            if (!check[x * 2]) {
                check[2 * x] = true;
                tmp.push(2 * x);
            }
        }
        if (q.empty() && !tmp.empty()) {
            q = tmp;
            tmp = queue<int>();
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int k, a;
    cin >> a >> k;

    cout << bfs(a, k);

    return 0;
}