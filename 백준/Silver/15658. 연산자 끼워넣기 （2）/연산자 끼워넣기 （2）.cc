#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int _min = INT_MAX;
int _max = INT_MIN;
int* num;

void func(int add, int sub, int mul, int div, int sum, int depth, int size) {
    int faoCnt[4] = { add, sub, mul, div };
    if (depth == size - 1) {
        if (_min > sum) {
            _min = sum;
        }
        if (_max < sum) {
            _max = sum;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int _sum = sum;

        if (faoCnt[i] > 0) {
            faoCnt[i] -= 1;
            if (i == 0) {
                _sum += num[depth + 1];
            }
            else if (i == 1) {
                _sum -= num[depth + 1];
            }
            else if (i == 2) {
                _sum *= num[depth + 1];
            }
            else if (i == 3) {
                if (sum < 0) {
                    _sum = -_sum;
                    _sum /= num[depth + 1];
                    _sum = -_sum;
                }
                else {
                    _sum /= num[depth + 1];
                }
            }
            func(faoCnt[0], faoCnt[1], faoCnt[2], faoCnt[3], _sum, depth + 1, size);
            faoCnt[i] += 1;
        }
    }

    return;
}

int main() {
    int n;
    //+ - x /
    int faoCnt[4] = { 0,0,0,0 };

    cin >> n;
    num = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> faoCnt[i];
    }

    func(faoCnt[0], faoCnt[1], faoCnt[2], faoCnt[3], num[0], 0, n);

    cout << _max << "\n" << _min;

    return 0;
}