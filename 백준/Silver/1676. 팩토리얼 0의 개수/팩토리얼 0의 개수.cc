#include <iostream>

using namespace std;

int main() {
    int n, zeroNum(0);
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int num = i;
        while (num % 5 == 0) {
            if (num % 5 == 0) {
                zeroNum++;
                num /= 5;
            }
        }
    }

    cout << zeroNum;

    return 0;
}