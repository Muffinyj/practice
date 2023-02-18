#include <iostream>

using namespace std;

int main() {
    int x;
    int s = (1 << 7) - 1;
    cin >> x;

    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if ((s >> i & 1) & ((x >> i) & 1)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}