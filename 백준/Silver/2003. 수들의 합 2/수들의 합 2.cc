#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[10001];

int main() {
    int n, m, cnt(0);
    cin >> n >> m;

    int* dp = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> dp[i];
    }

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = i; j < n; j++) {
            tmp += dp[j];
            if (tmp == m) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}