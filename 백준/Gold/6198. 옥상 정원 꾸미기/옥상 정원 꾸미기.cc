#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* tower = (int*)calloc(n, sizeof(int));
	int* stack = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> tower[i];
	}

	int tmp = 0;
	int top = 0, bottom = 0;
	long long int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			stack[top] = tower[i];
			tmp = stack[top];
			top += 1;
		}
		else {
			if (stack[top - 1] > tower[i]) {
				stack[top] = tower[i];
				top += 1;
			}
			else {
				while (stack[top - 1] <= tower[i] && top > 0) top -= 1;
				stack[top] = tower[i];
				top += 1;
			}
		}
		cnt += (top - 1);
	}

	cout << cnt;

	return 0;
}