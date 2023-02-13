#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int num[11];
int oper[4] = { 0, };
int _max = INT_MIN;
int _min = INT_MAX;

void doOperation(int idx, int n, int sum, int add, int sub, int mul, int div) {
    if (idx == n - 1) {
        if (_max < sum) {
            _max = sum;
        }
        if (_min > sum) {
            _min = sum;
        }
        return;
    }

    int tmp;
    if (add > 0) {
        tmp = sum + num[idx + 1];
        doOperation(idx + 1, n, tmp, add - 1, sub, mul, div);
        tmp = sum;
    }
    if (sub > 0) {
        tmp = sum - num[idx + 1];
        doOperation(idx + 1, n, tmp, add, sub - 1, mul, div);
        tmp = sum;
    }
    if (mul > 0) {
        tmp = sum * num[idx + 1];
        doOperation(idx + 1, n, tmp, add, sub, mul - 1, div);
        tmp = sum;
    }
    if (div > 0) {
        tmp = sum / num[idx + 1];
        doOperation(idx + 1, n, tmp, add, sub, mul, div - 1);
        tmp = sum;
    }
    
    return;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    doOperation(0, n, num[0], oper[0], oper[1], oper[2], oper[3]);

    cout << _max << "\n";
    cout << _min;

    return 0;
}