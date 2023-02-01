#include <iostream>
#include <cmath>

using namespace std;

int cnt = 0;

void getCnt(int cur, int sum, int n, int s, int* p){
    if (cur == n) {
        if (sum == s) {
            cnt++;
        }
        return;
    }

    getCnt(cur + 1, sum, n, s, p);
    getCnt(cur + 1, sum + p[cur], n, s, p);
}

int main() {
    int n, s;
    cin >> n >> s;

    int* p = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    getCnt(0, 0, n, s, p);

    //공집합
    if (s == 0) cnt--;

    cout << cnt;

    return 0;
}