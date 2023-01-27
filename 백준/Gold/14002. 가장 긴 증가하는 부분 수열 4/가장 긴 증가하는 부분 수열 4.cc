#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int** num = new int*[2];

    for (int i = 0; i < 2; i++) {
        num[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        cin >> num[0][i];
        num[1][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[0][i] > num[0][j]) {
                if (num[1][i] <= num[1][j]) {
                    num[1][j] = num[1][i]++;
                }
            }
        }
    }

    int max = num[1][0];
    int ptr = 0;
    for (int i = 1; i < n; i++) {
        if (max < num[1][i]) {
            max = num[1][i];
            ptr = i;
        }
    }

    cout << max << "\n";

    int* seq = new int[max];
    int cnt = 0;
    for (int i = ptr; i >= 0; i--) {
        int p = max - cnt;
        if (p == num[1][i]) {
            seq[p - 1] = num[0][i];
            cnt++;
        }
    }
    
    for (int i = 0; i < max; i++) {
        cout << seq[i] << " ";
    }

    delete[] seq;
    for (int i = 0; i < 2; i++) {
        delete num[i];
    }
    return 0;
}