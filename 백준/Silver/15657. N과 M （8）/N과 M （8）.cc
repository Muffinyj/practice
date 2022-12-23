#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
bool visited[9] = { false, };
int arr[9] = { 0, };
int v[9] = { 0, };

void nm(int num, int index) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        for (int i = num; i < n; i++) {
            arr[index] = v[i];
            nm(i, index + 1);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v, v + n);

    nm(0, 0);

    return 0;
}