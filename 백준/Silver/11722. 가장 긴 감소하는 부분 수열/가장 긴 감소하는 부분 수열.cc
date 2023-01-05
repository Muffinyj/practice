#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 1001

using namespace std;

int main() {
    int n, res(1);
    cin >> n;

    int* num = (int*)calloc(n, sizeof(int));
    int* dp = (int*)calloc(n, sizeof(int));
    memset(dp, 0, sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int x = num[i];
        for (int j = 0; j < i; j++) {
            if (x < num[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if (dp[i] > res) {
                        res = dp[i];
                    }
                }
            }
        }
        if (dp[i] == 0) {
            dp[i] = 1;
        }
    }

    cout << res;

    return 0;
}