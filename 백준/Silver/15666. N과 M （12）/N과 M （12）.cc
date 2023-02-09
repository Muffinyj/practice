#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#define MAX 1000000001

using namespace std;
int p[8];
int tmp[8];
bool visited[8];

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;

    return;
}

void getPermutation(int n, int r, int idx) {
    if (idx == r) {
        for (int i = 0; i < r; i++) {
            cout << tmp[i] << " ";
        }
        cout << "\n";

        return;
    }

    int prevNum = 0;
    for (int i = 0; i < n; i++) {
        if (idx != 0) {
            if (!visited[i] && prevNum != p[i] && tmp[idx - 1] <= p[i]) {
                tmp[idx] = p[i];
                prevNum = p[i];
                getPermutation(n, r, idx + 1);
            }
        }
        else {
            if (!visited[i] && prevNum != p[i]) {
                tmp[idx] = p[i];
                prevNum = p[i];
                getPermutation(n, r, idx + 1);
            }
        }
    }

    return;
}

int main() {
    int n, r;

    cin >> n >> r;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);

    getPermutation(n, r, 0);

    return 0;
}