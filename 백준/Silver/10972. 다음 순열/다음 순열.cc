#include <iostream>
#include <algorithm>

using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

int main() {
    int n;
    cin >> n;

    int* comp = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> comp[i];
    }

    int i = n - 1;

    while (i > 0 && comp[i - 1] >= comp[i]) {
        i--;
    }

    if (i <= 0) {
        cout << -1;
    }
    else {
        int j = n - 1;
        while (comp[j] <= comp[i - 1]) {
            j--;
        }

        swap(comp[j], comp[i - 1]);
        sort(comp + i, comp + n);

        for (int i = 0; i < n; i++) {
            cout << comp[i] << " ";
        }
    }

    return 0;
}