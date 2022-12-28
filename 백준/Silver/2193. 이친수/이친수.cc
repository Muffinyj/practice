#include <iostream>
#include <cstdlib>

using namespace std;

void dp(int n, long long int* ichinNum) {
    ichinNum[0] = 1;
    ichinNum[1] = 1;

    for (int i = 2; i < n; i++) {
        ichinNum[i] = ichinNum[i - 1] + ichinNum[i - 2];
    }

    return;
}

int main() {
    int n;
    cin >> n;
    long long int* ichinNum = (long long int*)calloc(n, sizeof(long long int));

    dp(n, ichinNum);

    cout << ichinNum[n - 1];

    return 0;
}