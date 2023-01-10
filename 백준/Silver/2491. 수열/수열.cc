#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* dp = (int*)calloc(n, sizeof(int));
    int* num = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    int plusCnt = 1;
    int minusCnt = 1;
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (num[i] - num[i - 1] > 0) {
            plusCnt++;
            minusCnt = 1;
        }
        else if (num[i] - num[i - 1] < 0) {
            plusCnt = 1;
            minusCnt++;
        }
        else {
            plusCnt++;
            minusCnt++;
        }
        if (dp[i - 1] < plusCnt) {
            dp[i] = plusCnt;
        }
        else if (dp[i - 1] < minusCnt) {
            dp[i] = minusCnt;
        }
        else {
            dp[i] = dp[i - 1];
        }
    }

    cout << dp[n - 1];

    return 0;
}