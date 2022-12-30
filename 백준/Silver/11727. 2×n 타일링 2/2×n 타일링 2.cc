#include <iostream>
#include <cstdlib>

using namespace std;

void dp(long long int* board, int n) {
    board[0] = 1;
    board[1] = 3;

    for (int i = 2; i < n; i++) {
        board[i] = (board[i - 1] + 2 * board[i - 2]) % 10007;
    }

    return;
}

int main() {
    int n;
    cin >> n;
    long long int* board = (long long int*)calloc(n, sizeof(long long int));

    dp(board, n);

    cout << board[n - 1];

    return 0;
}