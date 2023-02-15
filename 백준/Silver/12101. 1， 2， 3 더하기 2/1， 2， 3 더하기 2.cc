#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int add[10] = { 0, };
int n, k, cnt(0);
int ptr = 0;
bool flag = false;

void backTracking(int idx, int sum) {
    if (sum == n) {
        cnt++;
        if (cnt == k) {
            for (int i = 0; i < ptr; i++) {
                if (i < ptr - 1) {
                    cout << add[i] << "+";
                }
                else {
                    cout << add[i];
                }
            }
            exit(0);
        }
        return;
    }

    int tmpSum = 0;

    for (int i = 1; i <= 3; i++) {
        if (sum + i <= n) {
            add[ptr] = i;
            ptr++;

            backTracking(idx + 1, sum + i);

            ptr--;
            add[ptr] = 0;
        }
    }

    return;
}

int main() {
    cin >> n >> k;

    backTracking(0, 0);

    cout << -1;

    return 0;
}