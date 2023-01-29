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
        comp[i] = i + 1;
    }

    while (1) {
        int c = n - 1;
        for (int i = 0; i < n; i++) {
            cout << comp[i] << " ";
        }
        while (c > 0 && comp[c - 1] >= comp[c]) {
            c--;
        }
        
        if (c <= 0) {
            break;
        }

        int j = n - 1;
        while (comp[j] <= comp[c - 1]) {
            j--;
        }

        swap(comp[j], comp[c - 1]);
        sort(comp + c, comp + n);
        cout << "\n";
    }

    return 0;
}