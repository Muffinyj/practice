#include <iostream>
#include <cstdlib>
#define MAX 100001
#define MOD 1000000009

using namespace std;

//끝자리를 저장
unsigned int dp[MAX][3];

//끝자리기준으로
//1은 바로 이전거의 2,3자리를 합,
//2는 전전거의 1,3 자리의 합,
//3은 전전전거의 1,2 자리의 합
//왜냐하면 중복된 수는 나올 수 없기 때문이다.

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 2; i++) {
        dp[i][i] = 1;
    }
    for (int i = 2; i < MAX; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % MOD;
        if (i != 2) {
            dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % MOD;
        }
        else {
            dp[i][2] = 1;
        }
    }

    for (int j = 0; j < n; j++) {
        int num;
        cin >> num;

        cout << (dp[num - 1][0] + dp[num - 1][1] + dp[num - 1][2]) % MOD << "\n";
    }

    return 0;
}