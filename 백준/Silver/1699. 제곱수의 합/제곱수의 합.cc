#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* num = (int*)calloc(n, sizeof(int));
    int* dp = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (i - (int)sqrt(i) > 0) {
            for (int j = (int)sqrt(i); j >= 1; j--) {
                int x = (int)pow(j, 2);
                int tmp = dp[i - x] + 1;
                if (dp[i] > tmp) {
                    dp[i] = tmp;
                }
            }
        }
        else {
            dp[i] = 1;
        }
    }

    cout << dp[n];

    return 0;
}