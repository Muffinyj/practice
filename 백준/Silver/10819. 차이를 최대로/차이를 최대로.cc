#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

bool getNextPermutation(int* p, int n) {
    int i = n - 1;
    while (i > 0 && p[i] <= p[i - 1]) {
        i--;
    }

    if (i <= 0) {
        return false;
    }

    int j = n - 1;
    while (p[i - 1] >= p[j]) {
        j--;
    }
    swap(p[j], p[i - 1]);
    sort(p + i, p + n);

    return true;
}

int main() {
    int n;
    cin >> n;

    int* p = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);

    int m(0);
    while (1) {
        int tmp = 0;
        for (int i = 2; i <= n; i++) {
            tmp += abs(p[i - 2] - p[i - 1]);
        }
        if (m < tmp) {
            m = tmp;
        }

        if (!getNextPermutation(p, n)) {
            break;
        }
    }

    cout << m;

    return 0;
}