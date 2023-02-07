#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#define MAX 1000000001

using namespace std;

int _min = INT_MAX;
int mat[10][2];
int dp[1 << 10][2];

void Cooking(int v, int c, int n, int sumF) {
    if (n == c) {
        if (_min > abs(sumF) && v != 0) {
            _min = abs(sumF);
        }
        return;
    }

    Cooking(v, c + 1, n, sumF);

    v |= (1 << c);

    int& nowSour = dp[v][0];
    int& nowBitter = dp[v][1];

    if(nowSour == 0) {
        int s(1), b(0);
        for (int i = 0; i < n; i++) {
            if (v & (1 << i)) {
                s *= mat[i][0];
                b += mat[i][1];
            }
        }
        nowSour = s;
        nowBitter = b;
    }

    Cooking(v, c + 1, n, abs(nowSour - nowBitter));

    return;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        int a = 1, b = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                a*=mat[j][0];
                b+=mat[j][1];
            }
        }
    }

    Cooking(0, 0, n, 0);

    cout << _min;

    return 0;
}