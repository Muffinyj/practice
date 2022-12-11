#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;
	int* money = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> money[i];
	}

	int i = n - 1;
	int cnt = 0;
	while(k != 0) {
		if (money[i] <= k) {
			k -= money[i];
			cnt++;
		}
		else {
			i--;
		}
	}
	std::cout << cnt;
}