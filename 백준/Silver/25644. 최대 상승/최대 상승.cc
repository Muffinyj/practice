#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* dp = (int*)calloc(n, sizeof(int));
    int* stock = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        cin >> stock[i];
    }

    int min = stock[0];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] < stock[i] - min) {
            dp[i] = stock[i] - min;
        }
        else {
            dp[i] = dp[i - 1];
        }
        if (stock[i] < min) {
            min = stock[i];
        }
    }

    cout << dp[n - 1];

    return 0;
}