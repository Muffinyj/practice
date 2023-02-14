#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
int energy[10] = { 0, };
int te[10] = { 0, };
int _max = 0;

void getEnergy(int idx, int n, int sum) {
    if (idx == n - 2) {
        if (sum > _max) {
            _max = sum;
        }
        return;
    }

    int t[10] = { 0, };

    for (int i = 0; i < n - idx; i++) {
        t[i] = te[i];
    }

    for (int i = 1; i < n - 1; i++) {
        int tmp = sum + te[i - 1] * te[i + 1];

        for (int j = 0; j < n - idx; j++) {
            if (i < j) {
                te[j - 1] = te[j];
            }
        }

        getEnergy(idx + 1, n, tmp);

        for (int j = 0; j < n; j++) {
            te[j] = t[j];
        }

        tmp = sum;
    }

    return;
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> energy[i];
        te[i] = energy[i];
    }

    getEnergy(0, n, 0);

    cout << _max;

    return 0;
}