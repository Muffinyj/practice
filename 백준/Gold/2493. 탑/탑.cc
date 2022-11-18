#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* top = (int*)calloc(n, sizeof(int));
	int* receive = (int*)calloc(n, sizeof(int));
	int* stack = (int*)calloc(2*(n + 1), sizeof(int));

	for (int i = 0; i < n; i++) {
		cin >> top[i];
	}

	int t = 0, cnt = 0;
 	for (int i = 0; i < n; i++) {
		if (i == 0) {
			stack[t] = top[i];
			stack[t + 1] = i + 1;
			t += 2;
			receive[i] = 0;
			cnt++;
		}
		else {
			if (stack[t - 2] > top[i]) {
				receive[i] = stack[t - 1];
				stack[t] = top[i];
				stack[t + 1] = i + 1;
				t += 2;
			}
			else if (stack[t - 2] < top[i]) {
				while (stack[t - 2] < top[i] && t > 0) t -= 2;
				//empty
				if (t == 0) {
					receive[i] = 0;
					stack[t] = top[i];
					stack[t + 1] = i + 1;
					t += 2;
					cnt++;
				}
				//non empty
				else {
					receive[i] = stack[t - 1];
					stack[t] = top[i];
					stack[t + 1] = i + 1;
					t += 2;
				}
			}
		}
	}

	if (cnt == n) {
		cout << "0";
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << receive[i] << " ";
		}
	}

	return 0;
}