#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int arr[9] = { 0, };

void nm(int num, int index) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        for (int i = 1; i <= n; i++) {
            arr[index] = i;
            nm(i + 1, index + 1);
        }
    }
}

int main() {
	cin >> n >> m;
    nm(1, 0);

	return 0;
}