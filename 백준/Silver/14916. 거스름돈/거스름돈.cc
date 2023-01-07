#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    int n, res(1);
    cin >> n;

    int* dp = (int*)calloc((n / 5) + 1, sizeof(int));

    for (int i = 0; i < (n / 5) + 1; i++) {
        if (i != 0) {
            int five = i;
            int two = (n - five * 5) / 2;
            if(two * 2 + five * 5 == n){
                if ((dp[i - 1] > i + two) || dp[i] == 0) {
                    dp[i] = i + two;
                }
                else {
                    dp[i] = dp[i - 1];
                }
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        else {
            if ((n / 2) * 2 == n) {
                dp[i] = n / 2;
            }
            else {
                dp[i] = 0;
            }
        }
    }

    if (dp[n / 5] != 0) {
        cout << dp[(n / 5)];
    }
    else {
        cout << "-1";
    }

    return 0;
}