#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* dp = (int*)calloc(n, sizeof(int));
    int* box = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        cin >> box[i];
        dp[i] = 1;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (box[i] < box[j]) {
                if (dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    cout << max;

    return 0;
}