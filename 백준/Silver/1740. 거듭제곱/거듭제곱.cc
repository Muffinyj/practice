#include <iostream>
#include <cmath>
#define ll unsigned long long

using namespace std;

int main() {
    ll n;
    cin >> n;

    ll res = 0;
    ll c = 1, tmp = 1;
    int i = 0;
    bool binary[40] = { 0, };

    if (n > 1) {
        while (n >= c) {
            if (n & c) {
                binary[i] = true;
            }
            c = c << 1;
            i++;
        }

        for (int j = 0; j < i; j++) {
            if (binary[j]) {
                tmp = 1;
                for (int k = 0; k < j; k++) {
                    tmp *= 3;
                }
                res += tmp;
            }
        }
    }
    else {
        res = 1;
    }

    cout << res;

    return 0;
}