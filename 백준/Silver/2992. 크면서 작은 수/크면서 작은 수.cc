#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

bool getNextPermutation(int* p, int size) {
    int i = size - 1;
    while (p[i] <= p[i - 1] && i > 0) {
        i--;
    }

    if (i <= 0) {
        return false;
    }
    int j = size - 1;
    while (p[i - 1] >= p[j]) {
        j--;
    }
    swap(p[j], p[i - 1]);
    sort(p + i, p + size);
    
    return true;
}

int main() {
    string s;
    cin >> s;
    
    int size = s.size();
    int* p = new int[size];
    for (int i = 0; i < size; i++) {
        p[i] = s[i] - '0';
    }

    if (getNextPermutation(p, size)) {
        for (int i = 0; i < size; i++) {
            cout << p[i];
        }
    }
    else {
        cout << 0;
    }

    return 0;
}